program OlaMundo(output);

var
        A : single;
        s : single;
        prec: single;

begin
        A := 1;
        s := 2;

        while s>1 do
          begin
                A := A / 2;
                s := 1 + A;
          end;

        prec := 2 * A ;
        writeln(prec);
end.
