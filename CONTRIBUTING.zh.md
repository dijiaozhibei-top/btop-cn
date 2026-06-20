# 贡献指南

## 提交 Pull Request

- 解释你的变更或添加功能的理由。
  - 是否是被请求的变更或功能？
  - 如果不是，请先提出功能请求，获得反馈后再提交 PR。

- 将多个不相关的变更拆分为多个 PR。

- 如果是未报告错误的修复，请先提交 Bug 报告并链接到 PR。

- 纯粹的外观变更若无充分的价值说明，将不被接受。

## AI 生成代码

- 提交中包含 AI 生成代码的 PR 必须标注 **[AI generated]**。

  （包括直接向 LLM 提问生成的代码，以及通过"注释提示"生成的代码。）

- AI 仅用于**自动补全**模式生成样板代码或重复代码的，无需标注。

- 未披露 AI 使用情况的 PR 将被关闭，故意混淆 AI 使用情况的账号将被禁止再次贡献。

- "Vibe coding" 风格的 PR（提交者不懂其所提交的代码）将被驳回。

## 格式规范

### 遵循现有语法风格

- 缩进：**制表符（Tab）**
- 制表符宽度：**4**
- 使用替代运算符：`and`、`or`、`not`
- 左花括号 `{` 放在语句/条件同一行末尾

## 通用准则

- 不要强加编程风格。在合适的地方使用面向对象、函数式、数据驱动等风格。

- 使用 [RAII](https://en.cppreference.com/w/cpp/language/raii)。

- 充分利用标准算法库，观看 [C++ Seasoning](https://www.youtube.com/watch?v=W2tWOdzgXHA) 和 [105 STL Algorithms](https://www.youtube.com/watch?v=bFSnXNIsK4A) 获得灵感。

- 使用内置的 `fmt` 库进行字符串格式化，参见 [issue #535](https://github.com/aristocratos/btop/issues/535) 获取更多信息和示例。

  - 所有新代码应优先使用 `fmt::format` 或 `fmt::format_to`，而不是手动拼接字符串，以获得更好的性能。

- 如果已有包含的库能实现相同功能，不要添加新的 include。

- 使用描述性的变量名。

- 如果不明显，请添加注释说明代码的作用。

- 在较大的代码段中添加注释标签，说明当前正在做什么，以提高可读性。

- 避免写入磁盘。

- 使用日志功能时请合理使用，仅在重要变化时调用。

- 对你的代码进行基准测试，如果对性能有明显负面影响，请寻找替代方案。

如有问题，请创建新的讨论帖或发送邮件至 jakob@qvantnet.com

如需对此文档提出修改建议，请创建[新 Issue](https://github.com/aristocratos/btop/issues/new/choose)。
