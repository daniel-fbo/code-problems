#![allow(unused_imports, unused_variables, unused_mut, dead_code, unused_macros)]
use std::cmp::{max, min, Ordering, Reverse};
use std::collections::{BTreeMap, BTreeSet, BinaryHeap, HashMap, HashSet, VecDeque};
use std::io::{self, BufWriter, Read, Write};

macro_rules! debug {
    ($($x:expr),* $(,)?) => {
        #[cfg(debug_assertions)]
        { $(eprintln!("\x1b[32m[{}] {} = {:?}\x1b[0m", line!(), stringify!($x), &$x);)* }
    };
}

/// Lê toda a entrada de uma vez e entrega tokens.
/// Para problemas INTERATIVOS não use isto: leia linha a linha com stdin().read_line.
struct Scanner {
    it: std::str::SplitAsciiWhitespace<'static>,
}

impl Scanner {
    fn new() -> Self {
        let mut s = String::new();
        io::stdin().read_to_string(&mut s).unwrap();
        Self { it: Box::leak(s.into_boxed_str()).split_ascii_whitespace() }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T
    where
        T::Err: std::fmt::Debug,
    {
        self.it.next().expect("fim da entrada").parse().unwrap()
    }
    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T>
    where
        T::Err: std::fmt::Debug,
    {
        (0..n).map(|_| self.next()).collect()
    }
    fn chars(&mut self) -> Vec<u8> {
        self.it.next().expect("fim da entrada").as_bytes().to_vec()
    }
}

const MOD: i64 = 1_000_000_007;

fn solve(sc: &mut Scanner, out: &mut impl Write) {

}

fn main() {
    let mut sc = Scanner::new();
    let mut out = BufWriter::new(io::stdout().lock());
    let t: usize = sc.next(); // troque por `let t = 1;` se houver um único caso
    for _ in 0..t {
        solve(&mut sc, &mut out);
    }
}
