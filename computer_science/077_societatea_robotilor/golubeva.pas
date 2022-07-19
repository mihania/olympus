Program Societatea_robotilor;
Uses CRT;
Var A:Array[1..3] Of Longint;
(* numarul robotilor de virsta respectiva 1,2
sau 3 ani *)
N,K,I:Integer;
(* K-numarul robotilor construiti initial, Ndupa citi ani *)
X,Y,Rb,Nt:Longint;
(* X-nr grupurilor de 3 roboti, Y-nr grupurilor
de 5 roboti *)
Begin
ClrScr;
Write(‘nr roboti=’);ReadLn(K);
Write(‘nr de ani=’);ReadLn(N);
A[1]:=K; A[2]:=0; A[3]:=0; Nt:=K;
For I:=1 To N Do Begin
X:=0; Y:=0; Rb:=Nt;
While (Rb mod 3<>0) And (Rb>0) Do Begin Y:=Y+1;
Rb:=Rb-5 End;
If Rb>0 Then X:=Rb div 3;
A[3]:=A[2]; A[2]:=A[1]; A[1]:=5*X+9*Y;
Nt:=A[1]+A[2]+A[3]
End;
WriteLn(‘nr total=’,Nt);
ReadKey
End.
Problema 2
