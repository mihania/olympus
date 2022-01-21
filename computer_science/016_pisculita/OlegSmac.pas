var fin, fout : text;
    i, G, M, num : integer;
    price : array [0..4] of integer;
begin
  assign(fin, 'PISCULITA.IN');
  reset(fin);
  assign(fout, 'PISCULITA.OUT');
  rewrite(fout);
  readln(fin, G);
  price[0] := 1; //1 грамм
  price[1] := 5; //2 грамма
  price[2] := 10;//3 грамма
  price[3] := 25;//4 грамма
  price[4] := 50;//5 грамм
  
  num := G div 5;
  M := num * price[4];
  num := G mod 5;
  if (num >= 1) then
  begin
    M := M + price[num - 1];  
  end;
  
  writeln(fout, M);
  close(fin);
  close(fout);
end.