function solution(picks, minerals) {
  var answer = 0;
  let cnt = 0;
  let sort_str = [];
  picks.forEach((ele) => cnt += ele);
  minerals = minerals.slice(0, cnt * 5);

  let str = [];
  minerals.forEach((ele, index) => {
    if (ele === "diamond")
      str.push('a');
    else if (ele === "iron")
      str.push('b');
    else
      str.push('c');
    if (index % 5 === 4 || index == minerals.length - 1) {
      if (str.length !== 5) {
        while (str.length < 5)
          str.push('d');
      }
      str.sort();
      let s = '';
      str.forEach((ele) => {
        s += ele;
      })
      sort_str.push(s);
      str = [];
    }
  })
  sort_str.sort();

  console.log(sort_str);

  picks.forEach((pick, idx) => {
    while (pick-- && sort_str.length) {
      if (idx == 0) {
        let tmp = sort_str[0];
        for (let i = 0; i < tmp.length; i++) {
          if (tmp[i] !== 'd')
            answer++;
        }
        sort_str.shift();
      } else if (idx == 1) {
        let tmp = sort_str[0];
        for (let i = 0; i < tmp.length; i++) {
          if (tmp[i] === 'a') {
            answer += 5;
          } else if (tmp[i] != 'd') {
            answer++;
          }
        }
        sort_str.shift();
      } else {
        let tmp = sort_str[0];
        for (let i = 0; i < tmp.length; i++) {
          if (tmp[i] === 'a') {
            answer += 25;
          } else if (tmp[i] === 'b') {
            answer += 5;
          } else if (tmp[i] == 'c') {
            answer++;
          }
        }
        sort_str.shift();
      }
    }
  })
  return answer;
}