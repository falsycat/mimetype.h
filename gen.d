import std;

void main()
{
  stdin.byLine.
    filter!(x => x.length).
    map!(x => x.chop.split).
    each!((x) {
      `{ "%s", (const char*[]) { `.writef(x[0]);
      x[1..$].map!(x => `"`~x~`"`).chain(["NULL"]).join(", ").write;
      ", }, },".writeln;
    });
}
