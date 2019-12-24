# libcollect

`libcollect` is a C library of useful collection types. So far I have only
implemented a hash map. Because this is C these types are pretty unsafe and use
`void *`s everywhere. The pointers these containers store should be allocated on
the heap as they will be freed when the containers are freed.

## Types

- ::map

## License

This project is released in the public domain.
