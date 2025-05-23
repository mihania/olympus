﻿type BigInteger = record
     digits: array [0..2100] of byte;
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
    res.digits[res.size] := num mod 10;
    num := num div 10;
    res.size := res.size + 1;
  end;
  Init := res;
end;

function Add(a, b: BigInteger): BigInteger;
var sum, i : integer;
    res : BigInteger;
begin
  while (i < a.size) or (i < b.size) or (sum > 0) do
  begin
    sum := sum + a.digits[i] + b.digits[i];
    res.digits[i] := sum mod 10;
    sum := sum div 10;
    res.size := res.size + 1;
    i := i + 1;
  end;
  Add := res;
end;

function Subtract(a, b : BigInteger) : BigInteger;
var sub, i : integer;
    res : BigInteger;
begin
  res.size := 1;
  for i := 0 to a.size - 1 do
  begin
    sub := a.digits[i] - b.digits[i];
    if (sub < 0) then
    begin
      res.digits[i] := 10 - abs(sub);
      a.digits[i + 1] := a.digits[i + 1] - 1;
    end
    else begin
      res.digits[i] := sub;
    end;
    if (res.digits[i] <> 0) then 
    begin 
      res.size := i + 1;
    end;
  end;
  Subtract := res;
end;

procedure Print(var f: Text; a: BigInteger);
var i : integer;
begin
  for i := a.size - 1 downto 0 do
  begin
    write(fout, a.digits[i]);  
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
    sum_z := Subtract(sum_z, z[tail]);  
    z[tail] := p_copy;
    sum_z := Add(sum_z, z[tail]);
    tail := tail + 1;
    if (tail = q - 1) then
    begin
      tail := 0;
    end;
  end;
  
  Print(fout, Add(sum_z, p));
  close(fin);
  close(fout);
end.
