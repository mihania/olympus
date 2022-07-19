Program Decodificare;
Uses CRT;
Var F:Text;
X,Y:String; I:Byte;
(* X-mesajul codificat, Y-mesajul decodificat *)
Begin ClrScr;
Assign(F,’scrie.in’);Reset(F); ReadLn(F,X);
Close(F);
Y:=’’; I:=1;
While I<=Length(X) Do
I f ( X [ I ] = ’ S ’ ) A n d ( X [ I + 1 ] i n
[‘A’,’E’,’I’,’O’,’U’])
Then Begin Y:=Y+X[I+2]+X[I+1]; Inc(I,4) End
Else Begin Y:=Y+X[I]; Inc(I) End;
WriteLn(Y);
ReadKey
End.
