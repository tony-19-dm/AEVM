#include <stdio.h>
int bcint0[2] = { 1717992960, 8283750 };
int bcint1[2] = { 471341056, 3938328 };
int bcint2[2] = { 538983424, 3935292 };
int bcint3[2] = { 2120252928, 8282238 };
int bcint4[2] = { 2120640000, 6316158 };
int bcint5[2] = { 2114092544, 8273984 };
int bcint6[2] = { 33701376, 4071998 };
int bcint7[2] = { 811630080, 396312 };
int bcint8[2] = { 2120646144, 8283750 };
int bcint9[2] = { 2087074816, 3956832 };
int bcintA[2] = { 2118269952, 4342338 };
int bcintB[2] = { 1044528640, 4080194 };
int bcintC[2] = { 37895168, 3949058 };
int bcintD[2] = { 1111637504, 4080194 };
int bcintE[2] = { 2114092544, 8258050 };
int bcintF[2] = { 33717760, 131646 };
int bcintp[2] = { 2115508224, 1579134 };
int bcintm[2] = { 2113929216, 126 };

char *filename = "font.bin";
#include <stdio.h>

void
writeValuesToBinaryFile ()
{
  FILE *file = fopen (filename, "wb");
  if (file != NULL)
    {
      fwrite (bcint0, sizeof (int), 2, file);
      fwrite (bcint1, sizeof (int), 2, file);
      fwrite (bcint2, sizeof (int), 2, file);
      fwrite (bcint3, sizeof (int), 2, file);
      fwrite (bcint4, sizeof (int), 2, file);
      fwrite (bcint5, sizeof (int), 2, file);
      fwrite (bcint6, sizeof (int), 2, file);
      fwrite (bcint7, sizeof (int), 2, file);
      fwrite (bcint8, sizeof (int), 2, file);
      fwrite (bcint9, sizeof (int), 2, file);
      fwrite (bcintA, sizeof (int), 2, file);
      fwrite (bcintB, sizeof (int), 2, file);
      fwrite (bcintC, sizeof (int), 2, file);
      fwrite (bcintD, sizeof (int), 2, file);
      fwrite (bcintE, sizeof (int), 2, file);
      fwrite (bcintF, sizeof (int), 2, file);
      fwrite (bcintp, sizeof (int), 2, file);
      fwrite (bcintm, sizeof (int), 2, file);
      fclose (file);
    }
}

void
readValuesFromBinaryFile ()
{
  FILE *file = fopen (filename, "rb");
  if (file != NULL)
    {
      fread (bcint0, sizeof (int), 2, file);
      fread (bcint1, sizeof (int), 2, file);
      fread (bcint2, sizeof (int), 2, file);
      fread (bcint3, sizeof (int), 2, file);
      fread (bcint4, sizeof (int), 2, file);
      fread (bcint5, sizeof (int), 2, file);
      fread (bcint6, sizeof (int), 2, file);
      fread (bcint7, sizeof (int), 2, file);
      fread (bcint8, sizeof (int), 2, file);
      fread (bcint9, sizeof (int), 2, file);
      fread (bcintA, sizeof (int), 2, file);
      fread (bcintB, sizeof (int), 2, file);
      fread (bcintC, sizeof (int), 2, file);
      fread (bcintD, sizeof (int), 2, file);
      fread (bcintE, sizeof (int), 2, file);
      fread (bcintF, sizeof (int), 2, file);
      fread (bcintp, sizeof (int), 2, file);
      fread (bcintm, sizeof (int), 2, file);
      fclose (file);
    }
}
int
loadFont ()
{
  readValuesFromBinaryFile ();
  return 0;
}
