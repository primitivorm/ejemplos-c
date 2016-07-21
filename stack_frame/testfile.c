/*$type testfile.c */
/*$cl /nologo testfile.c*/
extern void __stdcall func1(int a);
extern void __stdcall func2(int a, int b, double d);
extern void __cdecl   func3(int b);
extern void __cdecl   func4(int a, int b, double d);

int __cdecl main(int argc, char **argv)
{
        func1(1);

        func2(2, 3, 4.);

        func3(5);

        func4(6, 7, 8.0);

        return 0;
}
