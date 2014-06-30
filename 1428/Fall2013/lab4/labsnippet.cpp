int x = 11,
    y = 12,
    z = 8;

if (y <= 14)
{
   if (0 != z)
      x *= .5;
   if (x == z - 3)
      z = x;
   else
      y = 15;
}

if (z > 7)
{
   z = 7;
   if (x < 11)
      x = y - z;
   else
      y = z - z;
}
else
{
   y = (x + z) / 4;
   if (y > 4)
      y /= 2;
   else
      y *= 2;

   if (y == 4)
      x = 2 * x + 4;
   else
      x = 4 * x - 2;
}
