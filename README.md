LoadNPSwfOffsets.cpp is the helper script which reads in timing offsets for the NPS by run from the master file, returned as an array of 1080 elements. Primary arguments are the run number and the file path to the master file (assumed to be in the same directory as the helper script by default).

Offsets are stored by run ranges in wfOffsets_master.txt, arranged in reading order (left to right, top to bottom) from block 0 to block 1080 for each run range.
