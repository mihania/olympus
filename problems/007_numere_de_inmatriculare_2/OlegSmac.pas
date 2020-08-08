var
  Tin : text;
  Tout : text;
  p,num,sum,i,j : integer;
begin
  assign(Tin,'C:\src\olympus\problems\007_numere_de_inmatriculare_2\TEST1.IN');
  reset(Tin);
  assign(Tout,'C:\src\olympus\problems\007_numere_de_inmatriculare_2\TEST1.OUT');
  rewrite(Tout);
  readln(Tin, p);
  for j := 1 to p do
  begin
    readln(Tin, num);
    while num > 9 do
    begin
      sum := 0;
      while num > 0 do
      begin
        i := num mod 10;
        sum := sum + i;
        num := num div 10;
      end;
      num := sum;
      writeln(Tout, num);
      if (num = 9) then writeln('inteligent');
      if (num = 8) then writeln('vorbaret');
      if (num = 7) then writeln('norocos');
      if (num <= 6) and (num >= 0) then writeln('obisnuit');
    end;
  end;
  close(Tin);
  close(Tout);
end.