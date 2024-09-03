cmake_minimum_required(VERSION 3.29)
project(CPSC_353)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPSC_353
		caesar_cipher.cpp
		caesar_cipher.h
		main.cpp
		otp_cipher.cpp
		otp_cipher.h
		vigenere_cipher.cpp
		vigenere_cipher.h
)
