mod linked_list;

fn main() {
    let mut x: linked_list::MyLinkedList<i32> = linked_list::MyLinkedList::new();

    x.push(10);
    x.push(20);
    x.push(30);
    x.push(40);

    println!("pop head: {}", x.pop().unwrap_or(0));
    println!("pop head: {}", x.pop().unwrap_or(0));

    x.traverse();


    x.drop();


    x.push(99);

    x.traverse();

}
