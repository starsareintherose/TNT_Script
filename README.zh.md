# guoyi.run

一步最大简约法系统发育分析的 TNT 脚本

![](./cover.svg)

[English README](./README.md) | [中文说明](./README.zh.md)

## 使用方法

* 将本脚本和你的 TNT 矩阵文件 `filename` 放在你存放 `tnt` 或 `exe` 可执行文件的文件夹中。

* 进入该目录，运行 `tnt`。

* 输入命令：`guoyi filename;`

## 引用方式

如果你使用了此脚本，**必须**引用本脚本，并引用 [TNT](https://www.lillo.org.ar/phylogeny/tnt/)。同时，恳请在致谢中致谢 张国一 (Guoyi Zhang) 。本脚本遵循 MIT 许可协议。

* Zhang G. guoyi.run: One-step TNT script for maximum parsimony phylogenetic analysis. *Zootaxa* 5642(1): 96–98. [https://doi.org/10.11646/zootaxa.5642.1.10](https://doi.org/10.11646/zootaxa.5642.1.10)

[点击此处获取 Bibtex 格式](./citation.bib)

## 功能简介

* 扩展的隐式加权（eiw 默认，K 值=12）、普通隐式加权（iw K=12）或等权加权（ew）。

* 树搜索方式：

  * 隐式枚举（ntax ≤ 20，但不适用于 eiw）
  * TBR Mult（迭代 1000 次，适用于 20 < ntax < 75，也适用于 ntax ≤ 20 且加权方式为 eiw）
  * Mult + Xmult（适用于 ntax ≥ 75，使用随机区段搜索，生成 50 次最优树，10 轮漂移、棘轮和融合）

* 支持生成严格共识树 / 多数规则共识树（不含 Bremer 支持以及其变体）/ 半严格共识树（不含 Bremer 支持以及其变体）

* 可计算相对 Bremer 支持、jackknife（1000 次）、bootstrap（1000 次）与对称重抽样（1000 次）

* 可在共识树上映射衍征性状（apomorphic characters）

* 可计算 TL（树长）、CI（一致性指数）、RI（保留指数）

## 脚本命令参数

Windows 用户使用：

```
tnt run guoyi.run filename datatype weight 0/K cons resample prefix;
```

Linux 和 Mac 用户使用：

```
tnt run guoyi.run filename datatype weight 0/K cons resample prefix,
```

说明如下：

* `datatype` 可选 `32`、`dna`、`prot`、`num` 或其他 TNT 支持的类型

  * `num`：数值数据，`dna`：DNA，`prot`：蛋白质，`32`：最大支持种类（默认）

* `weight` 可选 `iw`、`ew`、`eiw`

  * `iw`：隐式加权，`ew`：等权加权，`eiw`：扩展隐式加权（默认）
  * 注意：`ew` 后必须跟 `0`（K 值位置）

* `K` 值默认为 `12`，参考 Goloboff et al. 2017（*Cladistics* 34: 407–437）

  * 必须大于 0

* `cons` 合意树方式可选 `str`、`mjr`、`hlf`

  * `str`：严格合意（默认），`mjr`：多数规则，`hlf`：半严格

* `resample` 为数字之和，表示要进行哪些抽样支持计算：

  * 相对 Bremer 支持（rbrs）= 0.1
  * Bremer 支持（brs）= 0.2
  * Jackknife（jak）= 1
  * Bootstrap（boot）= 2
  * 对称重抽样（sym）= 4
    示例：jak + boot + sym = 7（默认值）
  * 注意：涉及 Bremer 的支持可能会改变树拓扑，请谨慎使用

* `prefix` 可以为空或任意字符串（默认为空）

## 输出结果说明

* 所有输出说明可在 `tnt.log` 文件末尾查看。

* `*.tre`：含物种名称的树；`*_no.tre`：不含物种名称的树。

* `*.tnt.tre`：可直接由 TNT 或 WinClada 读取。

* `*.ctf`：只能用 TNT 通过 `shortread` 命令读取。

* `*.svg`：树图文件，可用 [Inkscape](https://inkscape.org) 编辑。

* `original*`：原始共识树。

* `apo.tre`：映射了衍征性状的树。

* `resample.tre`：带支持值的共识树，可经 `tnt2figtree` 处理后由 FigTree 打开。

* `trees*.tre`：最简约树（MPTs），经 `tnt2figtree` 处理后可用 FigTree 打开。

* `resample/apo.log`：树标签信息。

* `eiw.log`：性状凹度信息。

* `homo.log`：所有性状的趋同信息。

* `report.log`：含 CI、RI、TL 报告。

* `winclada.ss`：包含数据矩阵和共识树，可直接由 WinClada 打开。

* `winclada.tre`：经 `tnt2winclada` 处理后生成，配合 TNT 矩阵文件 `filename` 可在 WinClada 中进行性状映射和趋同分析。（建议直接使用 `winclada.ss`）

## 更多信息

若需将 TNT 输出树转换为 WinClada（Nixon, 2021）或 FigTree 可读格式，请参考本仓库中的 `tnt2winclada` 与 `tnt2figtree`。

`runwincladtree.run` 可处理 [wincladtree 脚本](https://www.lillo.org.ar/phylogeny/tnt/scripts/wincladtree.run)，输入文件必须为 `$(PREFIX).winclada.ss` 或 `winclada.tree`。

## 交流群

QQ 群 118094340 加入请说明哪里看到的信息
