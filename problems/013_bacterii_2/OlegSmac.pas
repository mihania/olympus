type BigInteger = record
     bac: array [0..2100] of integer;
     size: integer;  // длина числа
end;

var
  fin : text;
  fout : text;
  p_int, q, N, i, j, tail : integer;
  z : array of BigInteger;
  p, sum_z, p_copy : BigInteger;
  
function Init(num: integer): BigInteger;
var res : BigInteger;
begin
  while (num > 0) do
  begin
    res.bac[res.size] := num mod 10;
    num := num div 10;
    res.size := res.size + 1;
  end;
  Init := res;
end;

function Add(a, b: BigInteger): BigInteger;
var sum, sum_i, len1, len2, i : integer;
    res : BigInteger;
begin
  len1 := a.size;
  len2 := b.size;
  while (len1 > 0) or (len2 > 0) or (sum > 0) do
  begin
    sum := sum + a.bac[i] + b.bac[i];
    sum_i := sum mod 10;
    sum := sum div 10;
    res.bac[i] := sum_i;
    res.size := res.size + 1;
    
    i := i + 1;
    len1 := len1 - 1;
    len2 := len2 - 1;
  end;
  Add := res;
end;

function Subtrac(a, b : BigInteger) : BigInteger;
var len1, len2, sub, i : integer;
    res : BigInteger;
begin
  len1 := a.size - 1;
  len2 := b.size - 1;
  if (len1 > len2) then i := len1
  else i := len2;
  res.size := i + 1;
  while (i >= 0) do
  begin
    sub := a.bac[i] - b.bac[i];
    if (sub < 0) then
    begin
      res.bac[i] := 10 - abs(sub);
      res.bac[i + 1] := res.bac[i + 1] - 1;
    end
    else begin
      res.bac[i] := sub;
    end;
    i := i - 1;
  end;
  Subtrac := res;
end;

procedure Print(var f: Text; a: BigInteger);
var i : integer;
begin
  for i := a.size - 1 downto 0 do
  begin
    write(f, a.bac[i]);  
  end;
end;  
  
begin
  assign(fin,'BACTERII.IN');
  reset(fin);
  assign(fout,'BACTERII.OUT');
  rewrite(fout);
  read(fin, p_int);
  read(fin, q);
  read(fin, N);
  p := Init(p_int);
  setLength(z, q - 1);
  tail := 0;
  for i := 0 to N - 1 do
  begin    
    p_copy := p;
    p := sum_z;
    sum_z := Subtrac(sum_z, z[tail]);  
    z[tail] := p_copy;
    sum_z := Add(sum_z, z[tail]);
    tail := tail + 1;
    if (tail > q - 2) then
    begin
      tail := 0;
    end;
  end;
  
  Print(fout, Add(sum_z, p));
  close(fin);
  close(fout);
end. 