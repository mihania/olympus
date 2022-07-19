Program Cantina;
Uses CRT;
Type Meniu=Record
Ora:1..24;
Val:100..500 End;
T=Array[1..100] Of Meniu;
Lin=Array[1..24] Of Meniu;
Var A:T; B:Lin; F:Text;
N,I:Byte; S:Longint;
Procedure Citire;
Begin
Assign(F,’cantina.in’); Reset(F);
ReadLn(F,N);
For I:=1 To N Do
ReadLn(F,A[I].Ora,A[I].Val); Close(F)
End;
Procedure Sort;
