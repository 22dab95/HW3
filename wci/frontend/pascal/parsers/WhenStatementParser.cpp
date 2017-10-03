/**
 * <h1>WhenStatementParser</h1>
 *
 * <p>Parse a Pascal WHEN statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "WhenStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

    using namespace std;
    using namespace wci::frontend::pascal;
    using namespace wci::intermediate;
    using namespace wci::intermediate::icodeimpl;

    bool WhenStatementParser::INITIALIZED = false;

    set<PascalTokenType> WhenStatementParser::ARROW_SET;

    void WhenStatementParser::initialize()
    {
        if (INITIALIZED) return;

        ARROW_SET = StatementParser::STMT_START_SET;
        ARROW_SET.insert(PascalTokenType::ARROW);

        set<PascalTokenType>::iterator it;
        for (it  = StatementParser::STMT_FOLLOW_SET.begin();
             it != StatementParser::STMT_FOLLOW_SET.end();
             it++)
        {
            ARROW_SET.insert(*it);
        }

        INITIALIZED = true;
    }

    WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
            : StatementParser(parent)
    {
        initialize();
    }

    ICodeNode *WhenStatementParser::parse_statement(Token *token) throw (string)
    {
        token = next_token(token);  // consume the WHEN

        // Create an IF node.
        ICodeNode *if_node = ICodeFactory::create_icode_node((ICodeNodeType) NT_IF);

        // Parse the expression.
        // The IF node adopts the expression subtree as its first child.
        ExpressionParser expression_parser(this);
        if_node->add_child(expression_parser.parse_statement(token));

        // Synchronize at the ARROW.
        token = synchronize(ARROW_SET);

        if (token->get_type() == (TokenType) PT_ARROW)
        {
            token = next_token(token);  // consume the ARROW
        }
        else {
            error_handler.flag(token, MISSING_RIGHT_ARROW, this);
        }

        // Parse the compound statement.
        // The IF node adopts the statement subtree as its second child.
        StatementParser statement_parser(this);
        if_node->add_child(statement_parser.parse_statement(token));
        token = current_token();

        token = next_token(token); // EAT THE FUCKING SEMICOLON

        // Make a reference to the parent node
        ICodeNode *temp_parent_if_node = if_node;

        // Keep nesting IF tree untill END token
        while(token->get_type() != (TokenType) PT_END)
        {
	    // Make an IF tree node
	    ICodeNode *temp_if_node = ICodeFactory::create_icode_node((ICodeNodeType) NT_IF);

            // Parse expression
            // The IF node adopts the expression subtree as its first child.
            temp_if_node->add_child(expression_parser.parse_statement(token));

            // Synchronize at the ARROW.
            token = synchronize(ARROW_SET);

            if (token->get_type() == (TokenType) PT_ARROW)
            {
                token = next_token(token);  // consume the ARROW
            }
            else {
                error_handler.flag(token, MISSING_RIGHT_ARROW, this);
            }

            // Parse the compound statement.
            // The IF node adopts the statement subtree as its second child.
            temp_if_node->add_child(statement_parser.parse_statement(token));
            token = current_token();

            token = next_token(token); // EAT THE FUCKING SEMICOLON

            // Look for an OTHERWISE.
	    if (token->get_type() == (TokenType) PT_OTHERWISE)
	    {
		token = next_token(token);  // consume the OTHERWISE

		// Synchronize at the ARROW.
		token = synchronize(ARROW_SET);

		if (token->get_type() == (TokenType) PT_ARROW)
		{
		    token = next_token(token);  // consume the ARROW
		}
		else 
		{
            error_handler.flag(token, MISSING_RIGHT_ARROW, this);
		}

		// Parse the compound statement.
		// The IF node adopts the statement subtree as its third child.
		temp_if_node->add_child(statement_parser.parse_statement(token));
		token = current_token();
	    }

	    // Attach IF tree to parent IF tree as its third child
	    temp_parent_if_node->add_child(temp_if_node);
	    // Re-assign third-child as new parent
	    temp_parent_if_node = temp_if_node;

        }

        if (token->get_type() == (TokenType) PT_END)
        {
	    token = next_token(token); // consume END
        }

        return if_node;
    }

}}}}  // namespace wci::frontend::pascal::parsers
