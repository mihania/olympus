function IsValid(subset : array of integer; k : integer) : boolean;
var i, len, prev : integer;
    res : boolean;
begin
  res := TRUE;
  for i := 0 to length(subset) - 1 do
  begin
    if (subset[i] <> 0) then
    begin
      if (i = 0) then
      begin
        prev := length(subset) - 1;
      end
      else begin
        prev := i - 1;  
      end;
      len := len + 1;
      if ((subset[prev] <> 0) and (length(subset) <> 1)) then
      begin
        res := FALSE;
        break;
      end;
    end;
  end;
  IsValid := res and (len = k);
end;

function Solve(n, k : integer) : integer;
var subset : array of integer;
    i, j, x, p, tmp, num : integer;
begin
  setLength(subset, n);
  tmp := 1;
  for i := 0 to n - 1 do //math.pow(2, time.length);
  begin
    tmp := tmp * 2;
  end;
  
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
    if IsValid(subset, k) then
    begin
      num := num + 1;  
    end;
    
    for j := 0 to length(subset) - 1 do //обнуление массива
    begin
      subset[j] := 0;
    end;
  end;
  Solve := num;
end;

var fin, fout : text;
    n, k, T, i : integer;
begin
  assign(fin, 'TESTS.IN');
  reset(fin);
  assign(fout, 'TESTS.OUT');
  rewrite(fout);
  readln(fin, T);
  for i := 0 to T - 1 do
  begin
    read(fin, n);
    read(fin, k);
    writeln(fout, Solve(n, k));
  end;
  close(fin);
  close(fout);
end.