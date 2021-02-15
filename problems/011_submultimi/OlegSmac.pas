function Check(a : array of integer; b : integer) : integer;
var i, res, len : integer;
begin
  for i := 0 to length(a) - 1 do
  begin
    if (a[i] <> 0) then
    begin
      len := len + 1;
      if ((i = 0) and (length(a) = 1)) or
         ((i = 0) and (a[i + 1] = 0)) or
         ((i > 0) and (a[i - 1] = 0)) then
      begin
        res := 1;
      end
      else begin
        res := 0;
        break;
      end;
    end;
  end;
  if (len <> b) or (a[0] <> 0) and (a[length(a)-1] <> 0) and (length(a) <> 1) then res := 0;
  Check := res;
end;

var fin, fout : text;
    i, j, n, k, x, p, tmp, num : integer;
    subset : array of integer;
begin
  assign(fin, 'SMULTIMI.IN');
  reset(fin);
  assign(fout, 'SMULTIMI.OUT');
  rewrite(fout);
  read(fin, n);
  read(fin, k);
  setLength(subset, n);
  
  tmp := 1;
  while i < n do //math.pow(2, time.length);
  begin
    tmp := tmp * 2;
    i := i + 1;
  end;
  writeln('tmp = ' , tmp);
  
  for x := 0 to tmp - 1 do //создание подмножеств
  begin
    p := x;
    i := 0;
    while (p > 0) do
    begin
      if (p mod 2 = 1) then
      begin
        subset[i] := i + 1;
      end;
      p := p div 2;
      i := i + 1;
    end;
    num := num + Check(subset, k);
    
    for j := 0 to length(subset) - 1 do //обнуление массива
    begin
      subset[j] := 0;
    end;
  end;
  
  writeln(fout, num);
  close(fin);
  close(fout);
end.