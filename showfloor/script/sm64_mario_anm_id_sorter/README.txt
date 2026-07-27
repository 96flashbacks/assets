"sm64_mario_anm_id_sorter" a script to sort Mario's animation IDs if their order is changed in any way. 
Ubuntu and GCC were used to create this script, so it's recommended to use them if you want to run this.

To run it, first it needs to be compiled, that can be done using the command "gcc sm64_mario_anm_id_sorter.c -o sm64_mario_anm_id_sorter.o".
To actually run the script, use the command "./sm64_mario_anm_id_sorter.o".

There are some requirements to make sure the script runs properly:

1) There must be an "ids.h" file in the same directory as the compiled script, the "ids.h" file is a copy of "mario_animation_ids.h" from the decomp.

1.1) Every animation enum in "ids.h" needs to have a commented out ID in hexadecimal next to it (/* 0xXX */), like the decomp.

1.2) There can't be any ID repeated in "ids.h" this will make the script give an error.

2) There also needs to be two folders in the same directory as the script, "anims" (with all the inc.c animations inside), 
and "anims_NEW" (should ideally be empty before running the script). "anims_NEW" is where all the replaced files will be stored, 
remember to keep it empty every time the script is ran, as it doesn't clean the folder on its own.

3) Every ID defined in "ids.h" must have an inc.c counterpart inside the "anims" folder, the script will give an error if there's a missing inc.c file.
