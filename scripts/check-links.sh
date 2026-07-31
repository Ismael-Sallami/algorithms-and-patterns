#!/usr/bin/env bash
# Opens every provenance link and fails if any of them is gone.
#
# The catalogue promises that each entry can be checked against the file it came
# from. That promise went quiet for months: eight repositories were renamed and
# reorganised at once, GitHub kept redirecting the name, and every link landed on
# a 404 that nobody saw. This is the step that would have said so.
#
# Redirects are followed on purpose: a repository rename is fine, a moved file is
# not, and only the final status tells them apart.
#
# @author Ismael Sallami Moreno
set -uo pipefail

cd "$(dirname "$0")/.." || exit 1

mapfile -t urls < <(
  grep -rhoE 'https://github\.com/[A-Za-z0-9_.-]+/[A-Za-z0-9_.-]+/blob/[^)"[:space:]]+' \
    README.md CATALOG.md patterns/ \
  | sed 's/#L.*$//' \
  | sort -u
)

echo "${#urls[@]} direcciones distintas"
rotos=0

for url in "${urls[@]}"; do
  codigo=$(curl -sL -o /dev/null -w '%{http_code}' --max-time 20 "$url")
  if [ "$codigo" = "200" ]; then
    printf '  ok    %s\n' "${url#https://github.com/}"
  else
    printf '  ROTO  %s  -> %s\n' "${url#https://github.com/}" "$codigo"
    rotos=$((rotos + 1))
  fi
done

echo
if [ "$rotos" -eq 0 ]; then
  echo "Todas las direcciones resuelven."
else
  echo "$rotos direcciones rotas."
  exit 1
fi
