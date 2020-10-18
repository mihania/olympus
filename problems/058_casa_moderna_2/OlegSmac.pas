program casa_moderna_2;
var
  fin, fout : text;
  o, N, i, j, p, res : integer;
  time : array of integer;
begin
  assign(fin, 'cas.in');
  reset(fin);
  assign(fout, 'cas.out');
  rewrite(fout);
  read(fin, N);
  setLength(time, N);
  for i := 0 to N - 1 do
  begin
    read(fin, o);
    time[i] := o;
  end;
  
  for i := 1 to length(time) - 1 do // сортировка массива
  begin
    for j := 0 to i do begin
      if (time[i] < time[j]) then
      begin
        p := time[i];
        time[i] := time[j];
        time[j] := p
      end;
    end;
  end;
  
  while (i < length(time)) do //расчеты
  begin
    if (time[i] >= i + 1) then res := 1
    else 
    begin
    res := 0; 
    break;
    end;
    i := i + 1;
    j := j + 1;
  end;
  write(fout, res);
  close(fin);
  close(fout);
end.
