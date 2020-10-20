program casa_moderna;
var
  fin, fout : text;
  o, v, N, i, j, s, pmin, tmp : integer;
  time : array of integer;
  price : array of integer;
begin
  assign(fin, 'cas.in');
  reset(fin);
  assign(fout, 'cas.out');
  rewrite(fout);
  read(fin, N);
  setLength(time, N);
  setLength(price, N);
  for i := 0 to N - 1 do //считывание данных в массив
  begin
    read(fin, o);
    time[i] := o;
    read(fin, v);
    price[i] := v;
  end;
  tmp := 1;
  for i := 0 to length(time) - 1 do
  begin
    for j := 1 to length(time) - 1 do
    begin
      if (time[i] = time[j]) then
      begin
        
      end;
    end;  
  end;
  
  for i := 0 to length(time) - 1 do
  begin
    writeln('time[',i,'] = ', time[i]);
    writeln('price[',i,'] = ', price[i]);
  end;
  writeln('s = ', s);
  writeln('pmin = ', pmin);
  close(fin);
  close(fout);
end.