
#!/bin/bash
printf "\e[0;34m#######################################################################\033[0m\n";
printf "\e[0;36m############ \e[0;32mProtonMail OpenPGP iOS Universal Library \033[0m \e[0;36m################\033[0m\n";
printf "\e[0;34m#######################################################################\033[0m\n";
printf "\e[0;32mInitial Generation Scripts. \033[0m\n"


BIN_PGP_LIB_NAME="libUniversalPGP.a"
XCODE_BUILD_BIN_OUT=${PWD}/../Bin/libs/
XCODE_BUILD_HEADER_OUT=${PWD}/../Bin/include/UniversalPGP
MAX_FILE_SIZE=26214400

BIN_DEVICE_OUTPUT=${XCODE_BUILD_BIN_OUT}/Release-iphoneos
BIN_SIMULATOR_OUTPUT=${XCODE_BUILD_BIN_OUT}/Release-iphonesimulator

if [  ! -d $BIN_DEVICE_OUTPUT ]; then
   printf "\e[0;31mPlease build ARM library!!! \033[0;31m\n"
   exit
fi

if [  ! -d $BIN_SIMULATOR_OUTPUT ]; then
  printf "\e[0;31mPlease build Intel library!!! \033[0;31m\n"
  exit
fi

if [  ! -d $XCODE_BUILD_HEADER_OUT ]; then
  printf "\e[0;31mPlease copy the header !!! \033[0;31m\n"
  exit
fi

printf "\e[0;32mStart Checking library Debugging Symbols Status.. \033[0m\n\n"
FILENAME=${BIN_DEVICE_OUTPUT}/${BIN_PGP_LIB_NAME}
FILESIZE=$(wc -c <$FILENAME)
if [ $FILESIZE -ge $MAX_FILE_SIZE ]; then
    printf "\e[0;32mStart Stripping Debugging Symbols for iOS Device Library. \033[0m\n"
	printf "\e[0;37mStripping File:\033[0m \e[0;36m ${BIN_PGP_LIB_NAME} \033[0m\n"
	strip -S ${FILENAME}
	printf "\e[0;37mStripping Done:\033[0m\n"
else
    printf "iOS Device Library have been removed Debugging Symbols!\n"
fi

FILENAME=${BIN_SIMULATOR_OUTPUT}/${BIN_PGP_LIB_NAME}
MAX_SIZE=26214400
FILESIZE=$(wc -c <$FILENAME)
if [ $FILESIZE -ge $MAX_FILE_SIZE ]; then
    printf "\e[0;32mStart Stripping Debugging Symbols for Simulator Library. \033[0m\n"
	printf "\e[0;37mStripping File:\033[0m \e[0;36m ${BIN_PGP_LIB_NAME} \033[0m\n"
	strip -S ${FILENAME}
	printf "\e[0;37mStripping Done\033[0m\n\n"
else
    printf "Simulator Library have been removed Debugging Symbols!\n\n"
fi

printf "\e[0;32mStart Build Universal Library. \033[0m\n"

UNIVERSAL_OUT_PATH=${PWD}/../out/OpenPGP
if [  ! -d $UNIVERSAL_OUT_PATH ]; then
   mkdir ${UNIVERSAL_OUT_PATH}
fi

UNIVERSAL_OUT_FILE_NAME="libOpenPGP.a"
DEVICE_OUT_PATH=${UNIVERSAL_OUT_PATH}/iOS
if [  ! -d $DEVICE_OUT_PATH ]; then
   mkdir ${DEVICE_OUT_PATH}
fi
SIMULATOR_OUT_PATH=${UNIVERSAL_OUT_PATH}/Simulator
if [  ! -d $SIMULATOR_OUT_PATH ]; then
   mkdir ${SIMULATOR_OUT_PATH}
fi
HEADER_OUT_PATH=${UNIVERSAL_OUT_PATH}/include
if [  ! -d $HEADER_OUT_PATH ]; then
   mkdir ${HEADER_OUT_PATH}
fi

cp -L ${BIN_DEVICE_OUTPUT}/${BIN_PGP_LIB_NAME} ${DEVICE_OUT_PATH}/${UNIVERSAL_OUT_FILE_NAME}
cp -L ${BIN_SIMULATOR_OUTPUT}/${BIN_PGP_LIB_NAME} ${SIMULATOR_OUT_PATH}/${UNIVERSAL_OUT_FILE_NAME}

lipo -create ${DEVICE_OUT_PATH}/${UNIVERSAL_OUT_FILE_NAME} ${SIMULATOR_OUT_PATH}/${UNIVERSAL_OUT_FILE_NAME} -o ${UNIVERSAL_OUT_PATH}/${UNIVERSAL_OUT_FILE_NAME}

printf "\e[0;32mCopy Header file. \033[0m\n"

cp -a ${XCODE_BUILD_HEADER_OUT}/. ${HEADER_OUT_PATH}/

printf "\e[0;32mBuild Universal Library Complete. \033[0m\n"

cd ${UNIVERSAL_OUT_PATH}
printf "\e[0;32m OUTPUT PATH: \033[0m\n"
pwd

printf "\n\e[0;32m DONE \033[0m\n\n"
