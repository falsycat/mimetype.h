mimetype.h
====

This library provides the following two functions:

```C
/* If the extension is unknown, returns NULL. */
const char* mimetype_from_ext(const char* ext);
const char* mimetype_from_ext_n(const char* ext, size_t len);
```

Mapping data is came from [nginx](https://github.com/nginx/nginx/blob/c108f04e85a15f4e1cc700b41999a92ce09a889d/conf/mime.types).
