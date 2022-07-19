Program Subsir_comun;
Uses CRT;
Const Nmax=127;
Var A,B,S:String; F:Text;
C:Array[1..Nmax,1..Nmax] Of Integer;
I,J,Is,Js,Ls,N,M:Integer;
Procedure Calc(I,J:Integer);
Var I1,J1,K:Integer;
Begin C[I,J]:=0;
If A[I]<>B[J] Then Exit;
K:=0;
For I1:=1 To I-1 Do
For J1:=1 To J-1 Do
If C[I1,J1]>K Then K:=C[I1,J1]; C[I,J]:=K+1;
If C[I,J]>Ls Then Begin
Is:=I; Js:=J; Ls:=C[I,J]
End
End;
Procedure Gaseste_subsir(I,J,Nr_el:Integer);
Var I1,J1:Integer;
Begin
S[Nr_el]:=A[I];
If C[I,J]>0 Then
For I1:=1 To I-1 Do
For J1:=1 To J-1 Do
If C[I1,J1]=Nr_el-1 Then Begin
Gaseste_subsir(I1,J1,Nr_el-1);
Exit
End
End;
Function Spc(S:String):String;
(* exclude spatiile *)
Begin
While Pos(‘ ‘,S)>0 Do Delete(S,Pos(‘ ‘,S),1);
Spc:=S
End;
Begin ClrScr;
Assign(F,’fraza.in’);Reset(F);
ReadLn(F,A); ReadLn(F,B); Close(F);
A:=Spc(A); B:=Spc(B);
Ls:=0;
For I:=1 To Length(A) Do
For J:=1 To Length(B) Do Calc(I,J);
If Ls>0 Then Gaseste_subsir(Is,Js,Ls);
For I:=1 To Ls Do Write(S[I]);
ReadKey
End.
