library/pictures/resize => get output of convert command to check if there is an output message and return false => done
object/generate.cpp => when generating the cache filename, don't force the .jpeg extension but use the input one
identity/identity.cpp => when writing the identity to the file, add the previous and the next user hash => done but don't need the previous one
identity/fileop.cpp => write_new_block_and_update_previous => need to review the code to make work the structs comparaisons 