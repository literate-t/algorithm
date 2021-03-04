## 스킬 트리

###### 문제 설명

선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다.

예를 들어 선행 스킬 순서가 `스파크 → 라이트닝 볼트 → 썬더`일때, 썬더를 배우려면 먼저 라이트닝 볼트를 배워야 하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.

위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서 `스파크 → 힐링 → 라이트닝 볼트 → 썬더`와 같은 스킬트리는 가능하지만, `썬더 → 스파크`나 `라이트닝 볼트 → 스파크 → 힐링 → 썬더`와 같은 스킬트리는 불가능합니다.

선행 스킬 순서 skill과 유저들이 만든 스킬트리[1](https://programmers.co.kr/learn/courses/30/lessons/49993#fn1)를 담은 배열 skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return 하는 solution 함수를 작성해주세요.

##### 제한 조건

- 스킬은 알파벳 대문자로 표기하며, 모든 문자열은 알파벳 대문자로만 이루어져 있습니다.
- 스킬 순서와 스킬트리는 문자열로 표기합니다.
  - 예를 들어, `C → B → D` 라면 "CBD"로 표기합니다
- 선행 스킬 순서 skill의 길이는 1 이상 26 이하이며, 스킬은 중복해 주어지지 않습니다.
- skill_trees는 길이 1 이상 20 이하인 배열입니다.
- skill_trees의 원소는 스킬을 나타내는 문자열입니다.
  - skill_trees의 원소는 길이가 2 이상 26 이하인 문자열이며, 스킬이 중복해 주어지지 않습니다.

##### 입출력 예

| skill   | skill_trees                         | return |
| ------- | ----------------------------------- | ------ |
| `"CBD"` | `["BACDE", "CBADF", "AECB", "BDA"]` | 2      |

##### 입출력 예 설명

- "BACDE": B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트립니다.
- "CBADF": 가능한 스킬트리입니다.
- "AECB": 가능한 스킬트리입니다.
- "BDA": B 스킬을 배우기 전에 C 스킬을 먼저 배워야 합니다. 불가능한 스킬트리입니다.

##### 풀이

두 가지 방법으로 풀어봤습니다. 첫 번째 방법은 옛날에 `java`로 풀었던 것을 참고해서 조금 멍청하게 풀었습니다. 멍청하다고 표현한 이유는 머리가 빠릿빠릿하게 돌아가지 않아서 멍청이가 된 기분으로 해결했기 때문인데, 성능은 괜찮은 편 같습니다. `skill`에서 비교해야 하는 인덱스의 순서가 지켜져야 하므로 지금 찾고 싶은 인덱스가 맞는지를 확인하는 것이 관건입니다. `flag`에 `false`가 하나라도 뜨면 다음 문자열을 비교하면 됩니다.

```javascript
function solution(skill, skill_trees) {
  let answer = 0;
  for (let i = 0; i < skill_trees.length; ++i) {
    let findIndex = 0;
    let flag = true;
    for (let j = 0; j < skill_trees[i].length; ++j) {
      for (let k = findIndex; k < skill.length; ++k) {
        let sktree = skill_trees[i][j];
        let sk = skill[k];
        if (sktree === sk) {
          if (k === findIndex) {
            ++findIndex;
          } else {
            flag = false;
          }
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) ++answer;
  }
  return answer;
}
```



두 번째 방법은 `javascript`스럽다고 생각합니다. `array`의 내장함수인 `map`, `filter`, `split` 등을 이용해 문자열 배열을 `skill`이 포함하는 문자에 맞게 조정한 뒤에 비교합니다. 코드는 간단하고 직관적이지만 첫 번째 방법에 비해 느립니다.

```javascript
function solution(skill, skill_trees) {
  let answer = 0;
  let trees = skill_trees
    // 문자열 배열의 각 요소를 분리한 문자열 배열을 만든 다음("ABC" -> ["A", "B", "C"])
  	// 각 요소 중 skill에 속하는 요소만 남기고 나서(skill이 "BC"라고 가정하면, ["B", "C"])
    // join()을 이용해 다시 합쳐 문자열을 만든다("BC")
    .map((tree) => tree.split("").filter((c) => skill.includes(c)))
    .map((data) => data.join(""));
  for (let i = 0; i < trees.length; ++i) {
    let flag = true;
    for (let j = 0; j < trees[i].length; ++j) {
      if (skill[j] !== trees[i][j]) {
        flag = false;
        break;
      }
    }
    if (flag) ++answer;
  }
  return answer;
}
```