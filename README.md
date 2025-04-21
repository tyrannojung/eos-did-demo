# eos-did-demo

A simple demonstration of a Decentralized Identifier (DID) system implementation on the EOS/Antelope blockchain.

## Overview

This project provides a testing environment for implementing a DID registry on the Antelope (formerly EOS) blockchain. The main components include:

- Government Block Producer node (authoritative block creator)
- Bank Read-only node
- DID Registry smart contract

## Architecture

- **Government BP Node**: Generates blocks and processes transactions
- **Bank Read-only Node**: Provides read-only access to chain data
- **DID Registry**: On-chain smart contract that maps `did:eos:<account>` identifiers to DID documents

## Getting Started

You can easily set up the development environment using Docker Compose:

```bash
docker compose -f spring-did.yml up -d
```

## Implementation Details

- Only the account owner can update their own DID document (permission-based access control)
- DID data can be read from any node
- DID documents stored on-chain in JSON format

## Purpose

This demo is intended for learning, proof of concept, and testing how to implement a DID system on the EOS/Antelope blockchain.
For production use, additional security mechanisms and feature enhancements would be necessary.
