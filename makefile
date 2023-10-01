GCCFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O2

run: libhtab.a libhtab.so wordcount wordcount-dynamic tail
	./wordcount
	./wordcount-dynamic

wordcount-dynamic: libhtab.so wordcount.c io.c
	gcc $(CFLAGS) wordcount.c io.c -L. -lhtab -o wordcount-dynamic

wordcount: libhtab.a wordcount.c io.c
	gcc $(CFLAGS) -static wordcount.c io.c -L. -lhtab -o wordcount

libhtab.so: htab_hash_function_dynamic.o htab_init_dynamic.o htab_size_dynamic.o htab_bucket_count_dynamic.o htab_resize_dynamic.o htab_find_dynamic.o htab_lookup_add_dynamic.o htab_erase_dynamic.o htab_for_each_dynamic.o htab_clear_dynamic.o htab_free_dynamic.o
	gcc -shared -fPIC $^ -o libhtab.so

libhtab.a:  htab_hash_function.o htab_init.o htab_size.o htab_bucket_count.o htab_resize.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o
	ar rc libhtab.a $^ && \
	ranlib libhtab.a

htab_hash_function_dynamic.o: htab_hash_function.c
	gcc -c -fPIC $(GCCFLAGS) htab_hash_function.c -o htab_hash_function_dynamic.o

htab_init_dynamic.o: htab_init.c
	gcc -c -fPIC $(GCCFLAGS) htab_init.c -o htab_init_dynamic.o

htab_size_dynamic.o: htab_size.c
	gcc -c -fPIC $(GCCFLAGS) htab_size.c -o htab_size_dynamic.o 

htab_bucket_count_dynamic.o: htab_bucket_count.c
	gcc -c -fPIC $(GCCFLAGS) htab_bucket_count.c -o htab_bucket_count_dynamic.o

htab_resize_dynamic.o: htab_resize.c
	gcc -c -fPIC $(GCCFLAGS) htab_resize.c -o htab_resize_dynamic.o 

htab_find_dynamic.o: htab_find.c
	gcc -c -fPIC $(GCCFLAGS) htab_find.c -o htab_find_dynamic.o 

htab_lookup_add_dynamic.o: htab_lookup_add.c 
	gcc -c -fPIC $(GCCFLAGS) htab_lookup_add.c -o htab_lookup_add_dynamic.o	

htab_erase_dynamic.o: htab_erase.c
	gcc -c -fPIC $(GCCFLAGS) htab_erase.c -o htab_erase_dynamic.o 

htab_for_each_dynamic.o: htab_for_each.c
	gcc -c -fPIC $(GCCFLAGS) htab_for_each.c -o htab_for_each_dynamic.o 

htab_clear_dynamic.o: htab_clear.c
	gcc -c -fPIC $(GCCFLAGS) htab_clear.c -o htab_clear_dynamic.o 

htab_free_dynamic.o: htab_free.c
	gcc -c -fPIC $(GCCFLAGS) htab_free.c -o htab_free_dynamic.o 

htab_hash_function.o: htab_hash_function.c
	gcc -c $(GCCFLAGS) htab_hash_function.c -o htab_hash_function.o

htab_init.o: htab_init.c
	gcc -c $(GCCFLAGS) htab_init.c -o htab_init.o

htab_size.o: htab_size.c
	gcc -c $(GCCFLAGS) htab_size.c -o htab_size.o 

htab_bucket_count.o: htab_bucket_count.c
	gcc -c $(GCCFLAGS) htab_bucket_count.c -o htab_bucket_count.o

htab_resize.o: htab_resize.c
	gcc -c $(GCCFLAGS) htab_resize.c -o htab_resize.o 

htab_find.o: htab_find.c
	gcc -c $(GCCFLAGS) htab_find.c -o htab_find.o 

htab_lookup_add.o: htab_lookup_add.c 
	gcc -c $(GCCFLAGS) htab_lookup_add.c -o htab_lookup_add.o	

htab_erase.o: htab_erase.c
	gcc -c $(GCCFLAGS) htab_erase.c -o htab_erase.o 

htab_for_each.o: htab_for_each.c
	gcc -c $(GCCFLAGS) htab_for_each.c -o htab_for_each.o 

htab_clear.o: htab_clear.c
	gcc -c $(GCCFLAGS) htab_clear.c -o htab_clear.o 

htab_free.o: htab_free.c
	gcc -c $(GCCFLAGS) htab_free.c -o htab_free.o 

tail: tail.c
	gcc $(GCCFLAGS) tail.c -o tail

clean:
	rm -rf *.o wordcount wordcount-dynamic libhtab.so libhtab.a tail