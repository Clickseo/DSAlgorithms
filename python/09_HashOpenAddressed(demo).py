from HashOpenAddressed import *

if __name__ == '__main__':
    h = HashOpenAddressed(11)
    h.insert(10)
    h.insert(21)
    h.delete(20)	# 아무 영향도 없어야 함
    h.insert(20)
    h.insert(5)
    h.insert(80)
    h.insert(32)
    h.delete(20)
    h.delete(44)

    item = 21
    slot = h.search(item)
    if slot == None:
	    print("Search Failed for", item)
    else:
	    print("Search for", item, "successful at slot", slot)
