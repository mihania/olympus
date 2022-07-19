Programul în limbajul Pascal:
Program Copacul;
Uses CRT;
Var N,I:Longint; (* N-numarul de zile *)
A,B,C,L:Real;
Begin
ClrScr;
Write(‘Nr de zile=’);ReadLn(N);
L:=1; A:=0; B:=1; C:=1;
For I:=2 To N Do Begin
C:=A+B; L:=L+C;
A:=B; B:=C
End;
WriteLn(C:14:0,’ ‘,L:14:0);
ReadKey
End.
Problema 2. Scri
