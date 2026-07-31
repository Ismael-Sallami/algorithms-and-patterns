# Pattern: Symmetric encryption of stored message bodies
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/oracle-dbms-project -> src/mensajeria/cifrado.py (complete file)
#          https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/mensajeria/cifrado.py#L1-L14
# Extract: verbatim, complete file.
#          Not a standalone build. See the source repository for the
#          full build context.

import os
# Lo usamos para el cifrado
from cryptography.fernet import Fernet
from dotenv import load_dotenv

# Cargamos los fichero env
load_dotenv()
#Cargamos la llave
llave_cifrado = os.getenv("CHATS_KEY")

if llave_cifrado:
    cipher_suite = Fernet(llave_cifrado.encode())
else:
    print("Error: No se encontró la llave ni en el sistema ni en el .env")
