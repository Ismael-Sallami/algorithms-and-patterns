#!/bin/bash
# Compiles and runs every reference implementation.
#
# Each file under reference/ asserts its own behaviour and prints nothing, so a
# silent run is a pass and a failed assertion aborts. That is what makes the badge
# mean something: the catalogue is executed, not just read.
#
# The files under patterns/ are extracts from earlier work, kept with a link back
# to the commit they came from. They are not compiled here: they are fragments of
# larger programs and do not stand alone.
set -u

root="$(cd "$(dirname "$0")/.." && pwd)"
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT

total=0
failed=0

while IFS= read -r source; do
  total=$((total + 1))
  name="$(basename "${source%.cpp}")"
  rel="${source#"$root"/}"

  if ! g++ -std=c++20 -O1 -Wall -Wextra -o "$work/$name" "$source" 2> "$work/$name.compile"; then
    echo "FAIL  $rel does not compile"
    sed 's/^/      /' "$work/$name.compile" | head -10
    failed=$((failed + 1))
    continue
  fi

  if ! "$work/$name" > "$work/$name.run" 2>&1; then
    echo "FAIL  $rel compiled but its assertions did not hold"
    sed 's/^/      /' "$work/$name.run" | head -10
    failed=$((failed + 1))
    continue
  fi

  echo "ok    $rel"
done < <(find "$root/reference" -name '*.cpp' | sort)

echo
if [ "$failed" -ne 0 ]; then
  echo "$failed of $total reference implementations failed"
  exit 1
fi
echo "$total reference implementations compile and verify themselves"
