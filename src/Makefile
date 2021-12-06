.PHONY: clean

CFLAGS=-Wall -g

driver: driver.o rbtree.o
test_rbtree_rotate: test_rbtree_rotate.o rbtree.o
test_rbtree_insert: test_rbtree_insert.o rbtree.o

clean:
	rm -f driver test_rotate test_rbtree_insert *.o