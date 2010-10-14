#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <locale.h>
#include <wchar.h>

int size,x;


wchar_t ftab[]={0x0021 ,
    0x0022 ,
    0x0026 ,
    0x0027 ,
    0x0028 ,
    0x002E ,
    0x0033 ,
    0x0034 ,
    0x0036 ,
    0x0037 ,
    0x003B ,
    0x003C ,
    0x003F ,
    0x0041 ,
    0x0042 ,
    0x0043 ,
    0x0044 ,
    0x0045 ,
    0x0046 ,
    0x0047 ,
    0x004A ,
    0x004B ,
    0x004C ,
    0x004D ,
    0x004E ,
    0x0050 ,
    0x0051 ,
    0x0052 ,
    0x0054 ,
    0x0055 ,
    0x0056 ,
    0x0059 ,
    0x005B ,
    0x005F ,
    0x0061 ,
    0x0062 ,
    0x0063 ,
    0x0064 ,
    0x0065 ,
    0x0066 ,
    0x0067 ,
    0x0068 ,
    0x0069 ,
    0x006A ,
    0x006B ,
    0x006C ,
    0x006D ,
    0x006E ,
    0x0072 ,
    0x0074 ,
    0x0076 ,
    0x0077 ,
    0x0079 ,
    0x007B ,
    0x203F ,
    0x2045 ,
                    0x2234 };

wchar_t rtab[]={0x00A1,
  0x201E,
  0x214B,
  0x002C,
  0x0029,
  0x02D9,
  0x0190,
  0x152D,
  0x0039,
  0x2C62,
  0x061B,
  0x003E,
  0x00BF,
  0x2200,
0x10412,
0x2183,
0x25D6,
0x018E,
0x2132,
0x2141,
0x017F,
0x22CA,
0x2142,
0x0057,
0x1D0E,
0x0500,
0x038C,
0x1D1A,
0x22A5,
0x2229,
0x1D27,
0x2144,
0x005D,
0x203E,
0x0250,
0x0071,
0x0254,
0x0070,
0x01DD,
0x025F,
0x0183,
0x0265,
0x0131,
0x027E,
0x029E,
0x0283,
0x026F,
0x0075,
0x0279,
0x0287,
0x028C,
0x028D,
0x028E,
0x007D,
0x2040,
0x2046,
0x2235};

size = sizeof(ftab) / sizeof(wchar_t);

int findchar (wchar_t w);

int findchar (wchar_t w)
{
int x;
for (x=0; x < size; x++) {
if (w == ftab[x]) {
        return (rtab[x]);
}

if (w == rtab[x]) {
        return (ftab[x]);
}

}
return (WEOF);


}
int main(int argc, char *argv[])

{
    int wide;

    wprintf (L"hello\n");
perror("wprintf");
    wide = (fwide(stdout, 0) == 0);
    printf("wide: %d", wide);



int ret;
wchar_t w=0x2021;
wchar_t new;

setlocale(LC_ALL, "");

/* for (x=0; x < size; x++) {
printf ("%lc\n", ftab[x]);
}
*/

while ( (w=getwchar()) != WEOF ) {
    new=findchar(w);
/* printf ("new: %x\n", new); */
    if (new != WEOF) {

           w=new;
    } 

ret=printf ("%lc", w);
/*printf ("ret: %d\n", ret);
ret=printf ("%x\n", w);
printf ("ret: %d\n", ret); */
}

if (ferror(stdin)) {
    perror ("read");
}

exit (0);

/* wchar_t ww[]={0x2131,0x0};
printf ("char %S\n\n", ww);
printf ("hex %x\n", ww);
printf ("int %d\n", ww);
*/
}
