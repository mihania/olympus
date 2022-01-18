program mihania;
var
  fin, fout: text;
  n, num, i: longint;

  function getDigit(num: longint): longint;
  var
     sum: longint;
  begin
     while(num > 9) do
     begin
       sum := 0;
       while (num > 0) do
       begin
         sum := sum + num mod 10;
         num := num div 10;
       end;
       num := sum;
     end;
     getDigit := num;
  end;

  function getQualification(digit: longint): String;
  begin
     case (digit) of
     7 : getQualification := 'norocos';
     8 : getQualification := 'vorbaret';
     9 : getQualification := 'inteligent';
     else
         getQualification := 'obisnuit';
     end;
  end;

begin
  assign(fin,'AUTO.IN');
  reset(fin);
  assign(fout,'AUTO.OUT');
  rewrite(fout);
  readln(fin, n);
  for i:= 1 to n do
  begin
    readln(fin, num);
    writeln(fout, getQualification(getDigit(num)));
  end;
  close(fin);
  close(fout);
end.
