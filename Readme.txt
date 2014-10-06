DeText v1.0
===========

  This is an extremely simple utility that reverses the effect of a LF -> CR/LF
translation that sometimes is performed accidentally during downloads from a
UNIX type host to an OS/2 or Windows PC.

Usage: detext SourceFile TargetFile

where SourceFile is the name of the corrupted file you want to fix and 
TargetFile is the file name to call the fixed file.

  Source code is included for the curious or those who want to compile it on a
different platform. It's generic C so should build on anything with a C 
compiler.

--
Brian Havard <brianh@kheldar.apana.org.au>
http://silk.apana.org.au/
