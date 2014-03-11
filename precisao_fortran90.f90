PROGRAM HELLO

double precision A, s, prec

A=1;
s=2;

do while (s>1)
   A=A/2;
   s=1+A;
end do

prec=2*A;

print*,prec
stop

END
