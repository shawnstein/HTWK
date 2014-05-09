HTWK
====

<b>Release Dates:</b>
  Uebung_1: 	unknown
  Uebung_2: 	27-04-2014
  Uebung_3: 	09-05-2014
  ADS_Prog1: 	09-05-2014

GitHub:
git add * && git commit -m "Kommentar" && git push origin master

average compile setup with debug:
cc src/main.c -g -std=c99 -o bin/a.out && gdb ./bin/a.out

average compile setup without debug:
cc src/main.c -g -std=c99 -o bin/a.out && ./bin/a.out 
