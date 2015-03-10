@ECHO OFF
REM
REM Change into your toolchain path
REM
setx LIBAROMA_GCC "D:\DevelTools\linaro\bin\arm-linux-gnueabihf-gcc.exe"
setx LIBAROMA_GPP "D:\DevelTools\linaro\bin\arm-linux-gnueabihf-g++.exe"
setx LIBAROMA_CFLAGS "-ftree-vectorize -mvectorize-with-neon-quad -fopenmp -mfloat-abi=hard -mfpu=neon -D__ARM_HAVE_NEON -DLIBAROMA_CONFIG_OPENMP=1"
setx LIBAROMA_CONFIG_DEBUG "5"
setx LIBAROMA_CONFIG_DEBUG_FILE "2"
setx LIBAROMA_CONFIG_DEBUG_MEMORY "1"
setx LIBAROMA_CONFIG_COMPILER_MESSAGE "1"
setx LIBAROMA_CONFIG_SHMEMFB "1"


REM setx LIBAROMA_CFLAGS "-fopenmp -DLIBAROMA_CONFIG_OPENMP=1"
REM setx LIBAROMA_CFLAGS "-mfloat-abi=hard -mfpu=neon -D__ARM_HAVE_NEON"