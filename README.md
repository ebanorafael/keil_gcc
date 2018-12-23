# keil_gcc
MDK ARM project compiling code with ARM GCC. 

This aims to compile code larger than 32 kbytes in Keil uVision. The exemple project given is a LoRa end point implementation. This repository, besides the Keil uVision project has a SW4STM32 project tha uses GCC as compiler too (so to compile it you must have Ac6 installed) for sake of comparing the two compiling output sizes.

The two IDE's are configured with the same compiler parameters

Below is given tables for comparison.

- No optimization

     |  Code Size (bytes) | FLASH Size (Kbytes) | Percentage 
-----|--------------------|---------------------|-----------
Ac6  |       118096       |         192         |   60.33   
-----|--------------------|---------------------|-----------
Keil |       116596       |         192         |   59.30   

- Optimization Level 1

     |  Code Size (bytes) | FLASH Size (Kbytes) | Percentage 
-----|--------------------|---------------------|-----------
Ac6  |      75268         |         192         |   38.28   
-----|--------------------|---------------------|-----------
Keil |      75336         |         192         |   38.32   

- Optimization Level 2 (size)

     |  Code Size (bytes) | FLASH Size (Kbytes) | Percentage 
-----|--------------------|---------------------|-----------
Ac6  |      67060         |         192         |   34.11   
-----|--------------------|---------------------|-----------
Keil |      66472         |         192         |   33.81   

- Optimization Level 2 (speed)

     |  Code Size (bytes) | FLASH Size (Kbytes) | Percentage 
-----|--------------------|---------------------|-----------
Ac6  |      74600         |         192         |   37.94   
-----|--------------------|---------------------|-----------
Keil |      74164         |         192         |   37.72   

- Optimization Level 3

     |  Code Size (bytes) | FLASH Size (Kbytes) | Percentage 
-----|--------------------|---------------------|-----------
Ac6  |      95280         |         192         |   44.46   
-----|--------------------|---------------------|-----------
Keil |      99140         |         192         |   50.43   

## Target configurations
In Project -> mlm32l07x01 -> 'Options for target mlm32l07x01' (Alt+F7) make the following changes (in the window tabs):

- Output

	Choose a suitable folder for the executable in the button Select Folder for Objects and name the generated executable in the dialog window Name of Executable and mark the Create Executable.

	Choose wheater to mark the other options.(Not mandatory).

- Listings

	Choose wheater to generate assembler's listing by marking Assembler Listing and selecting a folder for those files in the button Select Folder for Listings and for store another files you choose marking the other options. (Not mandatory)

	Choose wheater to generate Linker Listing files too.(Not mandatory)

- User

	Run #1 "C:\Program Files (x86)\GNU Tools Arm Embedded\7 2018-q2-update\bin\arm-none-eabi-size.exe" -A -d ./Outputs/Lora.elf; (**Show outupt file data size. Formatting and information is given by the parameters -A/-B, per** https://manned.org/arm-none-eabi-size/c5dd2ab5)

 	Run #2 "C:\Program Files (x86)\GNU Tools Arm Embedded\7 2018-q2-update\bin\arm-none-eabi-ld.exe" --print-memory-usage ./Objects/lora.o (**Print used size, total size and used size of memory regions created with the MEMORY command.**)(Not mandatory)[<a name="memory-usage">1</a>: Somehow doesn't allow gcc to produce the .elf, so for generating code, disable this option.]

- CC

	Preprocessor Symbols - Define: STM32L072xx,USE_B_L072Z_LRWAN1,USE_HAL_DRIVER,REGION_AU915 (**For this project to compile. For your specific project it may not be needed.**)

	Code Generation: disable all the check boxes.(Not mandatory)

	Choose the Optimization Level and Warning level.

	Include Path: ..\LoRaWAN\App\inc;..\Core\inc;..\..\..\..\..\..\Drivers\BSP\CMWX1ZZABZ-0xx;..\..\..\..\..\..\Drivers\STM32L0xx_HAL_Driver\Inc;..\..\..\..\..\..\Drivers\CMSIS\Device\ST\STM32L0xx\Include;..\..\..\..\..\..\Drivers\CMSIS\Include;..\..\..\..\..\..\Middlewares\Third_Party\LoRaWAN\Crypto;..\..\..\..\..\..\Middlewares\Third_Party\LoRaWAN\Mac;..\..\..\..\..\..\Middlewares\Third_Party\LoRaWAN\Phy;..\..\..\..\..\..\Middlewares\Third_Party\LoRaWAN\Utilities;..\..\..\..\..\..\Middlewares\Third_Party\LoRaWAN\Core;..\..\..\..\..\..\Drivers\BSP\Components\Common;..\..\..\..\..\..\Drivers\BSP\Components\sx1276;..\..\..\..\..\..\Drivers\BSP\B-L072Z-LRWAN1;..\..\..\..\..\..\Middlewares\Third_Party\LoRaWAN\Mac\region (**For this project to compile. For your specific project put the paths for the includes of your project**)

	Misc Controls: -mfloat-abi=soft -ffunction-sections (Not mandatory)

-Assembler

	Language/Code Generation: uncheck Enable ARM/Thumb Internetworking.(Not mandatory)

	Misc Controls: -mfloat-abi=soft

- Linker
	
	Enable only Use Math Libraries check box. (Not mandatory)

	Linker Script: ..\SW4STM32\mlm32l07x01\STM32L072CZYx_FLASH.ld

	Misc Controls: -specs=nosys.specs
                   -specs=nano.specs
                   -Xlinker --gc-sections [<a name="garbage-collector">2</a>: allow garbage collection of unused code sections, per https://manned.org/arm-none-eabi-ld.1 ]
                   -Xlinker --print-memory-usage [<a name="memory-usage2">3</a>: same action as Run #2 under User tab]







 	<sup>[1](#memory-usage1)</sup>
 	<sup>[2](#garbage-collector)</sup>
 	<sup>[3](#memory-usage2)</sup>

