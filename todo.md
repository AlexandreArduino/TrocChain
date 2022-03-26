library/pictures/resize => get output of convert command to check if there is an output message and return false => done
object/generate.cpp => when generating the cache filename, don't force the .jpeg extension but use the input one
identity/identity.cpp => when writing the identity to the file, add the previous and the next user hash => done but don't need the previous one
identity/fileop.cpp => write_new_block_and_update_previous => need to review the code to make work the structs comparaisons 
in object/save.cpp => add a section in the object struct called cache_name which contains the name in .cache/ => it will be used to copy the file from .cache/ to blockchain/pictures/ and to rename the file by the signature and add the exif data to store the descriptors => done
object/save.cpp => add a copy file function if needed
identity/identity.cpp => use the timestamp in ms not in s