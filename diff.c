#include "config.h"
#include "graph.h"
static int diff_indent_heuristic = 1;
static int diff_interhunk_context_default;
static unsigned ws_error_highlight_default = WSEH_NEW;
static NORETURN void die_want_option(const char *option_name)
{
	die(_("option '%s' requires a value"), option_name);
}

		options->submodule_format = DIFF_SUBMODULE_LOG;
		options->submodule_format = DIFF_SUBMODULE_SHORT;
	else if (!strcmp(value, "diff"))
		options->submodule_format = DIFF_SUBMODULE_INLINE_DIFF;
static int parse_one_token(const char **arg, const char *token)
{
	const char *rest;
	if (skip_prefix(*arg, token, &rest) && (!*rest || *rest == ',')) {
		*arg = rest;
		return 1;
	}
	return 0;
}

static int parse_ws_error_highlight(const char *arg)
{
	const char *orig_arg = arg;
	unsigned val = 0;

	while (*arg) {
		if (parse_one_token(&arg, "none"))
			val = 0;
		else if (parse_one_token(&arg, "default"))
			val = WSEH_NEW;
		else if (parse_one_token(&arg, "all"))
			val = WSEH_NEW | WSEH_OLD | WSEH_CONTEXT;
		else if (parse_one_token(&arg, "new"))
			val |= WSEH_NEW;
		else if (parse_one_token(&arg, "old"))
			val |= WSEH_OLD;
		else if (parse_one_token(&arg, "context"))
			val |= WSEH_CONTEXT;
		else {
			return -1 - (int)(arg - orig_arg);
		}
		if (*arg)
			arg++;
	}
	return val;
}

int git_diff_heuristic_config(const char *var, const char *value, void *cb)
{
	if (!strcmp(var, "diff.indentheuristic"))
		diff_indent_heuristic = git_config_bool(var, value);
	return 0;
}

	if (!strcmp(var, "diff.interhunkcontext")) {
		diff_interhunk_context_default = git_config_int(var, value);
		if (diff_interhunk_context_default < 0)
			return -1;
	if (!strcmp(var, "diff.renames")) {
		diff_detect_rename_default = git_config_rename(var, value);
	if (!strcmp(var, "diff.wserrorhighlight")) {
		int val = parse_ws_error_highlight(value);
		if (val < 0)
			return -1;
		ws_error_highlight_default = val;
		return 0;
	}

	if (git_diff_heuristic_config(var, value, cb) < 0)
		return -1;

	char hex[GIT_MAX_HEXSZ + 1];
 *   1. collect the minus/plus lines of a diff hunk, divided into
		FREE_AND_NULL(ecbdata->diff_words);
		width = term_columns() - strlen(line_prefix);
	QSORT(dir.files, dir.nr, dirstat_compare);
			damage = DIV_ROUND_UP(damage, 64);
	QSORT(dir.files, dir.nr, dirstat_compare);
	diff_set_mnemonic_prefix(o, "a/", "b/");
	if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}

	if (o->submodule_format == DIFF_SUBMODULE_LOG &&
	    (!one->mode || S_ISGITLINK(one->mode)) &&
	    (!two->mode || S_ISGITLINK(two->mode))) {
				&one->oid, &two->oid,
	} else if (o->submodule_format == DIFF_SUBMODULE_INLINE_DIFF &&
		   (!one->mode || S_ISGITLINK(one->mode)) &&
		   (!two->mode || S_ISGITLINK(two->mode))) {
		const char *del = diff_get_color_opt(o, DIFF_FILE_OLD);
		const char *add = diff_get_color_opt(o, DIFF_FILE_NEW);
		show_submodule_inline_diff(o->file, one->path ? one->path : two->path,
				line_prefix,
				&one->oid, &two->oid,
				two->dirty_submodule,
				meta, del, add, reset, o);
		return;
void fill_filespec(struct diff_filespec *spec, const struct object_id *oid,
		   int oid_valid, unsigned short mode)
		oidcpy(&spec->oid, oid);
		spec->oid_valid = oid_valid;
static int reuse_worktree_file(const char *name, const struct object_id *oid, int want_file)
	if (!FAST_WORKING_DIRECTORY && !want_file && has_sha1_pack(oid->hash))
	if (!want_file && would_convert_to_git(&the_index, name))
	if (oidcmp(oid, &ce->oid) || !S_ISREG(ce->ce_mode))
	    reuse_worktree_file(s->path, &s->oid, 0)) {

		/*
		 * Even if the caller would be happy with getting
		 * only the size, we cannot return early at this
		 * point if the path requires us to run the content
		 * conversion.
		 */
		if (size_only && !would_convert_to_git(&the_index, s->path))

		/*
		 * Note: this check uses xsize_t(st.st_size) that may
		 * not be the true size of the blob after it goes
		 * through convert_to_git().  This may not strictly be
		 * correct, but the whole point of big_file_threshold
		 * and is_binary check being that we want to avoid
		 * opening the file and inspecting the contents, this
		 * is probably fine.
		 */
		if (convert_to_git(&the_index, s->path, s->data, s->size, &buf, crlf_warn)) {
	FREE_AND_NULL(s->cnt_data);
	     reuse_worktree_file(name, &one->oid, 1))) {
				oid_to_hex_r(temp->hex, &null_oid);
				oid_to_hex_r(temp->hex, &one->oid);
			 * !(one->oid_valid), as long as
static const char *diff_abbrev_oid(const struct object_id *oid, int abbrev)
{
	if (startup_info->have_repository)
		return find_unique_abbrev(oid->hash, abbrev);
	else {
		char *hex = oid_to_hex(oid);
		if (abbrev < 0)
			abbrev = FALLBACK_DEFAULT_ABBREV;
		if (abbrev > GIT_SHA1_HEXSZ)
			die("BUG: oid abbreviation out of range: %d", abbrev);
		if (abbrev)
			hex[abbrev] = '\0';
		return hex;
	}
}

		strbuf_addf(msg, "%s%sindex %s..%s", line_prefix, set,
			    diff_abbrev_oid(&one->oid, abbrev),
			    diff_abbrev_oid(&two->oid, abbrev));
static void diff_fill_oid_info(struct diff_filespec *one)
	diff_fill_oid_info(one);
	diff_fill_oid_info(two);
	diff_fill_oid_info(p->one);
	diff_fill_oid_info(p->two);
	diff_fill_oid_info(p->one);
	diff_fill_oid_info(p->two);
	options->abbrev = DEFAULT_ABBREV;
	options->interhunkcontext = diff_interhunk_context_default;
	options->ws_error_highlight = ws_error_highlight_default;
	if (diff_indent_heuristic)
		DIFF_XDL_SET(options, INDENT_HEURISTIC);
		die(_("--name-only, --name-status, --check and -s are mutually exclusive"));
	if (40 < options->abbrev)
				die_want_option("--stat-width");
				die_want_option("--stat-name-width");
				die_want_option("--stat-graph-width");
				die_want_option("--stat-count");
static int parse_ws_error_highlight_opt(struct diff_options *opt, const char *arg)
	int val = parse_ws_error_highlight(arg);
	if (val < 0) {
		error("unknown value after ws-error-highlight=%.*s",
		      -1 - val, arg);
		return 0;
	else if (!strcmp(arg, "--indent-heuristic"))
		DIFF_XDL_SET(options, INDENT_HEURISTIC);
	else if (!strcmp(arg, "--no-indent-heuristic"))
		DIFF_XDL_CLR(options, INDENT_HEURISTIC);
		options->submodule_format = DIFF_SUBMODULE_LOG;
		return parse_ws_error_highlight_opt(options, arg);
	else if (!strcmp(arg, "--ita-invisible-in-index"))
		options->ita_invisible_in_index = 1;
	else if (!strcmp(arg, "--ita-visible-in-index"))
		options->ita_invisible_in_index = 0;
		options->orderfile = prefix_filename(prefix, optarg);
	else if (!strcmp(arg, "--no-abbrev"))
		options->abbrev = 0;
	else if ((argcount = parse_long_opt("line-prefix", av, &optarg))) {
		options->line_prefix = optarg;
		options->line_prefix_length = strlen(options->line_prefix);
		graph_setup_line_prefix(options);
		return argcount;
	}
		char *path = prefix_filename(prefix, optarg);
		options->file = xfopen(path, "w");
		free(path);
const char *diff_aligned_abbrev(const struct object_id *oid, int len)
	if (len == GIT_SHA1_HEXSZ)
		return oid_to_hex(oid);

	abbrev = diff_abbrev_oid(oid, len);
	if (abblen < GIT_SHA1_HEXSZ - 3) {
		static char hex[GIT_MAX_HEXSZ + 1];

	return oid_to_hex(oid);
			diff_aligned_abbrev(&p->one->oid, opt->abbrev));
			diff_aligned_abbrev(&p->two->oid, opt->abbrev));
		fprintf(opt->file, "%s", diff_line_prefix(opt));
static void patch_id_add_string(git_SHA_CTX *ctx, const char *str)
{
	git_SHA1_Update(ctx, str, strlen(str));
}

static void patch_id_add_mode(git_SHA_CTX *ctx, unsigned mode)
{
	/* large enough for 2^32 in octal */
	char buf[12];
	int len = xsnprintf(buf, sizeof(buf), "%06o", mode);
	git_SHA1_Update(ctx, buf, len);
}

static int diff_get_patch_id(struct diff_options *options, struct object_id *oid, int diff_header_only)
		diff_fill_oid_info(p->one);
		diff_fill_oid_info(p->two);
		patch_id_add_string(&ctx, "diff--git");
		patch_id_add_string(&ctx, "a/");
		git_SHA1_Update(&ctx, p->one->path, len1);
		patch_id_add_string(&ctx, "b/");
		git_SHA1_Update(&ctx, p->two->path, len2);

		if (p->one->mode == 0) {
			patch_id_add_string(&ctx, "newfilemode");
			patch_id_add_mode(&ctx, p->two->mode);
			patch_id_add_string(&ctx, "---/dev/null");
			patch_id_add_string(&ctx, "+++b/");
			git_SHA1_Update(&ctx, p->two->path, len2);
		} else if (p->two->mode == 0) {
			patch_id_add_string(&ctx, "deletedfilemode");
			patch_id_add_mode(&ctx, p->one->mode);
			patch_id_add_string(&ctx, "---a/");
			git_SHA1_Update(&ctx, p->one->path, len1);
			patch_id_add_string(&ctx, "+++/dev/null");
		} else {
			patch_id_add_string(&ctx, "---a/");
			git_SHA1_Update(&ctx, p->one->path, len1);
			patch_id_add_string(&ctx, "+++b/");
			git_SHA1_Update(&ctx, p->two->path, len2);
		}
					GIT_SHA1_HEXSZ);
					GIT_SHA1_HEXSZ);
	git_SHA1_Final(oid->hash, &ctx);
int diff_flush_patch_id(struct diff_options *options, struct object_id *oid, int diff_header_only)
	int result = diff_get_patch_id(options, oid, diff_header_only);
N_("inexact rename detection was skipped due to too many files.");
N_("only found copies from modified paths due to too many files.");
N_("you may want to set your %s variable to at least "
   "%d and retry the command.");
		warning(_(degrade_cc_to_c_warning));
		warning(_(rename_limit_warning));
		warning(_(rename_limit_advice), varname, needed);
		options->file = xfopen("/dev/null", "w");
	QSORT(q->queue, q->nr, diffnamecmp);
		    const struct object_id *oid,
		    int oid_valid,
		fill_filespec(one, oid, oid_valid, mode);
		fill_filespec(two, oid, oid_valid, mode);
		 const struct object_id *old_oid,
		 const struct object_id *new_oid,
		 int old_oid_valid, int new_oid_valid,
		SWAP(old_mode, new_mode);
		SWAP(old_oid, new_oid);
		SWAP(old_oid_valid, new_oid_valid);
		SWAP(old_dirty_submodule, new_dirty_submodule);
	fill_filespec(one, old_oid, old_oid_valid, old_mode);
	fill_filespec(two, new_oid, new_oid_valid, new_mode);
					  &df->oid,
		notes_cache_put(driver->textconv_cache, &df->oid, *outbuf,
int textconv_object(const char *path,
		    unsigned mode,
		    const struct object_id *oid,
		    int oid_valid,
		    char **buf,
		    unsigned long *buf_size)
{
	struct diff_filespec *df;
	struct userdiff_driver *textconv;

	df = alloc_filespec(path);
	fill_filespec(df, oid, oid_valid, mode);
	textconv = get_textconv(df);
	if (!textconv) {
		free_filespec(df);
		return 0;
	}

	*buf_size = fill_textconv(textconv, df, buf);
	free_filespec(df);
	return 1;
}
