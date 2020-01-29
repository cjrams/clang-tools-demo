# [Clang tools](https://clang.llvm.org/docs/ClangTools.html)
* [Extra tools](https://clang.llvm.org/extra/index.html)
* [JSON Compilation Database Format Specification](https://clang.llvm.org/docs/JSONCompilationDatabase.html)
* [Using clang-tidy and clang-format](https://www.labri.fr/perso/fleury/posts/programming/using-clang-tidy-and-clang-format.html)

## [Clang Format](https://clang.llvm.org/docs/ClangFormat.html)
* Configure your file with [configurator](https://zed0.co.uk/clang-format-configurator/) or [clangformat.com](https://clangformat.com/)
* Run on latest git commit ```git diff -U0 --no-color HEAD^ | clang-format-diff.py -i -p1```
* Run on all files in the project ```find . \( -name "*.cpp" -or -name "*.h" \) -exec clang-format -style=file -i {} +```
* Also can be added to your favourite editor and ide
* Possible issues. 

```
- #include <a//b.h>
- EM_ASM_ARGS({if (something === 'something') {}) 
----
+ #include <a //b.h> 
- EM_ASM_ARGS({if (something == = 'something') {}) 
```
```
// clang-format off
EM_ASM_ARGS({
if (something === 'something') {
...
})
// clang-format on
```
 * clang-format can reorder your includes, if rule is applied, be aware this will discover missing includes in your includes, that work by luck 😅

## [Clang Tidy](https://clang.llvm.org/extra/clang-tidy/)
  * [Integrate Clang-Tidy into CMake](https://ortogonal.github.io/cmake-clang-tidy/)
  * [How to integrate clang-tidy with CMake](https://gitlab.kitware.com/cmake/cmake/issues/18926)
  * Enable partial with https://gitlab.kitware.com/cmake/cmake/issues/18926
     * One project ```set_property(TARGET "${PROJ_NAME}" PROPERTY CXX_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*;")```
     * Multimple targets ```set_target_properties(${PROJ_LIST} PROPERTIES CXX_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*;")``` 
 * Videos
   * [C++ Weekly SE - clang-tidy Auto Fixes in Compiler Explorer - Tribute to Hubert Matthews](https://youtu.be/EfYMKOMc738)
   * [C++ Weekly - Ep 148 - clang-tidy Checks To Avoid](https://youtu.be/oxpsHk1yq88)
   * [C++ Weekly - Ep 3 Intro to clang-tidy](https://m.youtube.com/watch?v=OchPaGEH4TE)

* ### Create your clang-tidy rules
 * [Future Developments in clang-query](https://steveire.wordpress.com/2018/11/11/future-developments-in-clang-query/) 
 * [Composing AST Matchers in clang-tidy](https://steveire.wordpress.com/2018/11/20/composing-ast-matchers-in-clang-tidy/)
 * [Debugging Clang AST Matchers](https://steveire.wordpress.com/2019/04/16/debugging-clang-ast-matchers/)
 * [Refactor with Clang Tooling at code::dive 2018](https://steveire.wordpress.com/2019/01/02/refactor-with-clang-tooling-at-codedive-2018/)
 * [The Future of AST-Matching refactoring tools (EuroLLVM and ACCU)](https://steveire.wordpress.com/2019/04/30/the-future-of-ast-matching-refactoring-tools-eurollvm-and-accu/)
 * [Exploring Clang Tooling Part 1: Extending Clang-Tidy](https://devblogs.microsoft.com/cppblog/exploring-clang-tooling-part-1-extending-clang-tidy/)
 * [Exploring Clang Tooling Part 2: Examining the Clang AST with clang-query](https://devblogs.microsoft.com/cppblog/exploring-clang-tooling-part-2-examining-the-clang-ast-with-clang-query/)
 * [Exploring Clang Tooling Part 3: Rewriting Code with clang-tidy](https://devblogs.microsoft.com/cppblog/exploring-clang-tooling-part-3-rewriting-code-with-clang-tidy/)

## Clang sanitizers
 * [Address sanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
 * [Thead sanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)
 * [Memory sanitizer](https://clang.llvm.org/docs/MemorySanitizer.html)
 * [Undefined Behaviour sanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
 * [Data flow sanitizer](https://clang.llvm.org/docs/DataFlowSanitizer.html)
 * Videos
   * [C++ Weekly - Ep 84 - C++ Sanitizers](https://youtu.be/MB6NPkB4YVs)

     
 
