type BigInteger = record
     digits : array [0..256] of byte;
     size : integer;
end;

const M = 255;

var fin, fout : text;
    str, S_str : string;
    N, i, j, max_idx : longint;
    S, tmp : BigInteger;
    A : array [0..M] of BigInteger;
    dp : array [0..M] of BigInteger;
    idx : array [0..M] of longint;
    pred : array [0..M] of BigInteger;
    cities : array [0..M] of longint;

function Init(num : string) : BigInteger;
var res : BigInteger;
    i, err : integer;
begin
    num := trim(num); 
    for i := length(num) downto 1 do
    begin
        val(num[i], res.digits[res.size], err);
        res.size := res.size + 1;
    end;
    Init := res;
end;

function Compare(a, b : BigInteger) : integer; //0 - они равны, -1 - меньше, 1 - больше
var len, i, res : integer;
begin
    if (a.size > b.size) then
    begin
        len := a.size;
    end
    else len := b.size;
    for i := len downto 0 do
    begin
        if (a.digits[i] < b.digits[i]) then
        begin
            res := -1;
            break;
        end;
        if (a.digits[i] > b.digits[i]) then
        begin
            res := 1;
            break;
        end;
    end;
    Compare := res;
end;

function Add(a, b : BigInteger) : BigInteger;
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

procedure Print(var f : text; a : BigInteger);
var i : integer;
begin
    for i := a.size - 1 downto 0 do
    begin
        write(fout, a.digits[i]);
    end;
end;

begin
  assign(fin, 'REGE.IN');
  reset(fin);
  assign(fout, 'REGE.OUT');
  rewrite(fout);
  read(fin, N);
  readln(fin, S_str);
  S := Init(S_str);
  max_idx := -1;
  for i := 0 to N - 1 do
  begin
    readln(fin, str);
    A[i] := Init(str);
  end;

  for i := 1 to N - 1 do
  begin
    for j := 0 to i - 1 do
    begin
      if (Compare(A[i], A[j]) = -1) then
      begin
        tmp := A[i];
        A[i] := A[j];
        A[j] := tmp;
      end;
    end;
  end;

  for i := N - 1 downto 0 do
  begin
    if (Compare(A[i], S) <= 0) then
    begin
      dp[i] := A[i];
      idx[i] := i;
      pred[i] := A[i];
      cities[i] := 1;
      for j := i + 1 to N - 1 do
      begin
        if (Compare(A[i], Subtract(S, dp[j])) <= 0) and {ostalis coldati?}
           (Compare(A[i], pred[j]) = -1) and {sled gosudarstvo bolshe uje zavoevanih?}
           (Compare(dp[i], Add(dp[j], A[i])) = -1) then {zavoevivaem bolshuiu territiriu cem imeem?}
        begin
          dp[i] := Add(dp[j], A[i]);
          idx[i] := j;
          pred[i] := Subtract(pred[j], A[i]);
          cities[i] := cities[j] + 1;
        end;
      end;
      if (max_idx = -1) or (Compare(dp[max_idx], dp[i]) = -1) then
      begin
        max_idx := i;
      end;
    end;
  end;

  if (max_idx = -1) then
  begin
    write(fout, cities[max_idx], ' ');
    Print(fout, S, ' ');
  end
  else begin
    write(fout, cities[max_idx], ' ');
    Print(fout, Subtract(S, dp[max_idx]));
    writeln(fout, ' ');
    while (max_idx <> idx[max_idx]) do
    begin
      Print(fout,  A[max_idx]);
      writeln(fout, ' ');
      max_idx := idx[max_idx];
    end;
  end;
  Print(fout, A[max_idx]);

  close(fin);
  close(fout);
end.
