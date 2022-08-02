Bitoreum Core v2.5
===========================

What is Bitoreum?

Bitoreum is a decentralized financial technology accessible to everyone that is fast, reliable and
secure with negligible transaction costs. Bitoreum has its own blockchain, which is a fork of
Raptoreum codebase with ASIC resistant POW algorithm and consensus ensuring Smartnodes
which make the network immune to 51% attacks. Bitoreum coins can be mined on both CPU
and GPU. Bitoreum cares about privacy and has an integrated CoinJoin mechanism that allows
to hide the balance directly in the wallet.

Problems Bitoreum attempts to solve

Bitoreum is a transparent and scalable financial system that aims to make cryptocurrencies
accessible to everyone. There are four main directions in which we want to contribute.

1. Make managing BTRM easy for everyone by deploying mobile wallets for the major
mobile OS, such as Android and IOS.

2. Promote the adoption of cryptocurrencies by offering a payment gateway service. The
service will provide a free plugin for small businesses to facilitate online transactions in
cryptocurrency. Customers will be able to pay for goods and services in BTRM, while an
entrepreneur will receive fiat money to his/her credit card.

3. We think that all cryptocurrencies deserve to have access to the investors and to be
tradable at an exchange. To achieve this goal we want to remove entry barriers in the form
of high exchange listing fees and to offer everyone Bitroeum Exchange with its own
blockchain, where all coins interested in listing can be traded against Bitroeum.

4. We believe that everyone should be able to get a part of the financial pie with high returns
that is usually accessible only to rich investors. That is why everyone can earn coins with
modest initial investment by deploying Smartnodes and contributing to the blockchain
stability and security.

The roadmap to our goals can be found at our official webpage https://bitoreum.org/

License
-------

Bitoreum Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is meant to be stable. Development is done in separate branches.
[Tags](https://github.com/bitoreum/bitoreum/tags) are created to indicate new official,
stable release versions of Bitoreum Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
