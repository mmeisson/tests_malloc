
> Project migrated to https://gitlab.com/mmeisson_42/correction-tests/malloc

## HOW TO USE

    This directory should be in the project's folder

    Add the directory where header's project is located in Makefile's 'INCS_PATH'
        Ex : INCS_PATH = ../includes ./ ./printf/incs
    If "malloc.h" or equivalent is in the directory ../includes
    Note : Should work on both linux and macos / freebsd(?)


#### Compile
```
make
```

#### I changed my malloc
```
make re
```

#### Run
```
./test_malloc # Test with the real one to show that tests just works
./run.sh ./test_malloc # Test with the project's malloc
```

### My malloc is not aligned

I think you should align it, however, you can disable align checks in test.h ( set SAFE to something else than 1 )



#### I want to contribute

Thanks. I don't want to test UB. bt_* functions just store uglyli a stackstrace ( why bt ? Don't remember ). Pull requests are welcome.


#### You use a printf ?

It is my printf, it doesn't use malloc it all. A bug is located in this printf, but it won't affect these tests.
