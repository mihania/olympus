Program livada_de_meri;
Uses CRT;
Type Livada=Array[1..100,1..10] Of Longint;
Patrat=Record
I,J,Lat,Rot:Byte
End;
Var L:Livada; M,N,I,J:Byte;
MereMax,Mere:Longint; P,Pmax:Patrat;
Procedure Citeste;
Var F:Text;
Begin
A s s i g n ( F , ’ l i v a d a . i n ’ ) ; R e s e t ( F ) ;
ReadLn(F,M,N);
For I:=1 To M Do Begin
For J:=1 To N Do Read(F,L[I,J]);
ReadLn(F) End; Close(F)
End;
Function Min(A,B:Byte):Byte;
Begin If A<B Then Min:=A Else Min:=B End;
Function Calc:Longint;
Begin
With P Do
Calc:=L[I,J+Rot]+L[I+Rot,J+Lat]+L[I+Lat,J+LatRot]+L[I+Lat-Rot,J]
End;
Begin
Citeste; MereMax:=0;
With P Do
For I:=1 To M Do
For J:=1 To N Do
For Lat:=1 To Min(M-I,N-J) Do
For Rot:=0 To Lat-1 Do
Begin Mere:=Calc;
If Mere>MereMax Then Begin MereMax:=Mere;
Pmax:=P End
End;
ClrScr;
With Pmax Do Begin
WriteLn(‘(‘,I:4,’,’,J+Rot:4,’)’);
WriteLn(‘(‘,I+Rot:4,’,’,J+Lat:4,’)’);
WriteLn(‘(‘,I+Lat:4,’,’,J+Lat-Rot:4,’)’);
WriteLn(‘(‘,I+Lat-Rot:4,’,’,J:4,’)’) End;
ReadKey
End.
