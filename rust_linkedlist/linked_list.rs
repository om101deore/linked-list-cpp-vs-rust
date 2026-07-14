use std::fmt::Display;

pub type Link<T> = Option<Box<Node<T>>>;

pub struct MyLinkedList<T> {
    pub head: Link<T>,
}

pub struct Node<T> {
    value: T,
    next: Link<T>,
}

impl<T: Display> MyLinkedList<T> {
    pub fn new() -> Self {
        Self { head: None }
    }

    pub fn push(&mut self, value: T) {
        let nn: Link<T> = Some(Box::new(Node {
            value,
            next: self.head.take(),
        }));
        self.head = nn;
    }

    pub fn pop(&mut self) -> Option<T> {

        return match self.head.take() {
            Some(h) => {
                let val = h.value;
                self.head = h.next;
                Some(val)
            }
            None => None,
        };

    }

    pub fn traverse(&self) {
        let mut node = &self.head;

        loop {
            match node {
                Some(n) => {
                    print!("{} -> ", n.value);
                    node = &n.next
                }
                None => 
                {
                    println!("()");
                    break;
                }
            }
        }
    }

    pub fn drop(&mut self){
        self.head = None;
    }
}
