//LegendBoi @AnmolMajithia. Similar to LRU custom

class FirstUnique {

    class Node {
        int a;
        Node next = null;
        Node prev = null;
        Node(int x) {
            a = x;
        }
    }

    Node head = null;
    Node tail = null;
    HashMap<Integer, Integer> removed = new HashMap<>();
    HashMap<Integer, Integer> uniques = new HashMap<>();

    public FirstUnique(int[] nums) {
        for(int i = 0; i < nums.length; i++) {
            add(nums[i]);
        }
    }

    public int showFirstUnique() {
        if(head != null) {
            return head.a;
        }
        return -1;
    }

    public void add(int value) {
        if(removed.containsKey(value)) {
            return;
        }
        else if(head == null) {
            head = new Node(value);
            uniques.put(value,value);
            tail = head;
        }
        else if(head.a == value) {
            head = head.next;
            removed.put(value,value);
            uniques.remove(value);
        }
        else if(uniques.containsKey(value)) {
            Node temp = head;
            Node secLast = head;
            while (temp != null) {
                if (temp.a == value) {
                    secLast.next = temp.next;
                    removed.put(value, value);
                    uniques.remove(value);
                    break;
                }
                secLast = temp;
                temp = temp.next;
            }
            if (temp == null) {
                secLast.next = new Node(value);
            }
        }
        else {
            tail.next = new Node(value);
            tail = tail.next;
            uniques.put(value,value);
        }
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */
