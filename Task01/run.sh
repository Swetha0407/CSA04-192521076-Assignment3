#!/bin/bash
set -u; cd "$(dirname "$0")"; mkdir -p outputs
gcc -std=c11 -Wall -Wextra -fPIC -c encryption.c -o encryption.o
ar rcs libencrypt.a encryption.o
gcc -std=c11 -Wall -Wextra -static app.c libencrypt.a -o app_static || gcc -std=c11 -Wall -Wextra app.c libencrypt.a -o app_static
gcc -std=c11 -Wall -Wextra -fPIC -shared encryption.c -o libencrypt.so
gcc -std=c11 -Wall -Wextra app.c -L. -lencrypt -Wl,-rpath,'$ORIGIN' -o app_dynamic
gcc -std=c11 -Wall -Wextra dlopen_app.c -ldl -o app_dlopen
{ echo '== sizes =='; ls -lh app_static app_dynamic libencrypt.a libencrypt.so; echo '== ldd =='; ldd ./app_dynamic; echo '== dlopen/dlsym/maps =='; ./app_dlopen; echo '== time dynamic =='; /usr/bin/time -v ./app_dynamic; echo '== time static =='; /usr/bin/time -v ./app_static; echo '== missing library =='; ./app_dlopen ./missing.so || true; } > outputs/run.txt 2>&1
cp libencrypt.so libencrypt_v1.so; sed 's/v1/v2/' encryption.c > encryption_v2.c; gcc -std=c11 -Wall -Wextra -fPIC -shared encryption_v2.c -o libencrypt.so; ./app_dlopen > outputs/replaced_library.txt 2>&1
echo 'Inspect outputs/run.txt; run a long-lived process to compare simultaneous /proc/<pid>/maps.'
