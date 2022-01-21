type BigInteger = record
     digits: array [0..2100] of byte;
     size: integer;  // длина числа
end;

var
  fin : text;
  fout : text;
  N, i, j, p_int, q_int : integer;
  p, q, tmp : BigInteger;
  
function Init(num: integer): BigInteger;
var res : BigInteger;
begin
  while (num > 0) do
  begin
    res.digits[res.size] := num mod 10;
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
  if (len1 > len2) then res.size := len1
  else res.size := len2;
  while (i < res.size) do
  begin
    sum := sum + a.digits[i] + b.digits[i];
    sum_i := sum mod 10;
    sum := sum div 10;
    res.digits[i] := sum_i;
    if (i + 1 = res.size ) and (sum = 1) then
    begin
      res.size := res.size + 1;
    end;
    i := i + 1;
  end;
  Add := res;
end;

procedure Print(var f: Text; a: BigInteger);
var i : integer;
begin
  for i := a.size - 1 downto 0 do
  begin
    write(f, a.digits[i]);
  end;
end;  
  
begin
  assign(fin,'BACTERII.IN');
  reset(fin);
  assign(fout,'BACTERII.OUT');
  rewrite(fout);
  read(fin, p_int);
  read(fin, q_int);
  read(fin, N);
  p := Init(p_int);
  q := Init(q_int);
  
  for i := 0 to N - 1 do
  begin
    tmp := Add(p, q);
    q := p;
    p := tmp;
  end;
  Print(fout, Add(p, q));
  close(fin);
  close(fout);
end. 
