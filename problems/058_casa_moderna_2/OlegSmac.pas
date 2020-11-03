program casa_moderna_2;
var
  fin, fout : text;
  N, i, j, p, res, zero : integer;
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
    read(fin, time[i]);
  end;
  
  for i := 1 to length(time) - 1 do // сортировка массива
  begin
    for j := 0 to i do begin
      if (time[i] < time[j]) then
      begin
        p := time[i];
        time[i] := time[j];
        time[j] := p;
      end;
    end;
  end;
  
  i := 0;
  for j := 0 to length(time) - 1 do
  begin
    if (time[j] = 0) then
    begin
      zero := zero + 1;
    end;
    if (time[j] <> 0) and (i + 1 <= time[j]) then
    begin
      i := i + 1;
    end;
  end;
<<<<<<< HEAD
  writeln('i = ', i);
  writeln('zero = ', zero);
  i := i + zero;
  
  if (i = length(time)) then
=======
  if (i = length(time) - 1) then
>>>>>>> 9886d6a0350416c2ac644ff875682f70a774e620
  begin
    res := 1;
  end
  else
  begin
    res := 0;
  end;
  write(fout, res);
<<<<<<< HEAD
  write(res);
=======
>>>>>>> 9886d6a0350416c2ac644ff875682f70a774e620
  close(fin);
  close(fout);
end.
